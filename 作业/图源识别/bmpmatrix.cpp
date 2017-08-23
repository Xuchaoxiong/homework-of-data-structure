#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1) 

typedef unsigned short WORD; //WORD����unsigned short
typedef unsigned long DWORD;
typedef long LONG;
typedef unsigned char BYTE;
#define TRUE 1;
#define FALSE 0;

typedef struct tagBITMAPFILEHEADER { // bmfh 
	WORD bfType; // λͼ�ļ������ͣ�����ΪBM
	DWORD bfSize; // ͼƬ�Ĵ�С�����ֽ�Ϊ��λ��
	WORD bfReserved1; // λͼ�ļ������֣�����Ϊ0
	WORD bfReserved2; // λͼ�ļ������֣�����Ϊ0
	DWORD bfOffBits; // λͼ���ݵ���ʼλ�ã��������λͼ�ļ�ͷ��ƫ������ʾ�����ֽ�Ϊ��λ,54���ֽ�
} BITMAPFILEHEADER; // BITMAPFILEHEADER����һ���ṹ������

typedef struct tagBITMAPINFOHEADER{ // bmih 
	DWORD biSize; // ���ṹ��ռ���ֽ���
	LONG biWidth; // λͼ�Ŀ�ȣ�������Ϊ��λ
	LONG biHeight; // λͼ�ĸ߶ȣ�������Ϊ��λ
	WORD biPlanes; // Ŀ���豸�ļ��𣬱���Ϊ1
	WORD biBitCount;// ÿ�����������λ����������1(˫ɫ),4(16ɫ)��8(256ɫ)��24(���ɫ)֮һ
	DWORD biCompression; // λͼѹ�����ͣ������� 0(��ѹ��),1(BI_RLE8ѹ������)��2(BI_RLE4ѹ������)֮һ
	DWORD biSizeImage; // λͼ�Ĵ�С�����ֽ�Ϊ��λ
	LONG biXPelsPerMeter; // λͼˮƽ�ֱ��ʣ�ÿ��������
	LONG biYPelsPerMeter; // λͼ��ֱ�ֱ��ʣ�ÿ��������
	DWORD biClrUsed;// λͼʵ��ʹ�õ���ɫ���е���ɫ��
	DWORD biClrImportant;// λͼ��ʾ��������Ҫ����ɫ��
} BITMAPINFOHEADER; 

typedef struct tagRGBQUAD{
	BYTE rgbBlue;//��ɫ�����ȣ�ֵ��ΧΪ0-255)
	BYTE rgbGreen;//��ɫ�����ȣ�ֵ��ΧΪ0-255)
	BYTE rgbRed;//��ɫ�����ȣ�ֵ��ΧΪ0-255)
	BYTE rgbReserved;//����������Ϊ0
}RGBQUAD;

BITMAPFILEHEADER bmpFileHeader; //λͼ�ļ�ͷ
BITMAPINFOHEADER bmpInfoHeader; //λͼ��Ϣͷ
RGBQUAD *pColorTable;            //��ɫ��ע��24λ���ɫͼ����ɫ��
unsigned char *pBmpData;        //λͼ����
unsigned char *pGrayData;        //�Ҷ�ͼ������
unsigned char **GrayMatrix;	 //�Ҷ�ͼ�����ݶ�ά����

/**
* ������: readBmp
* ��  ��: fileName -- Ҫת����ͼƬ��
* ��  ��: ��ȡfileName�ļ���Ϣ����ȡ�ɹ�����TRUE����֮������FALSE
*/
bool readBmp(char *fileName)
{
    FILE *fp = fopen(fileName,"rb");    //�Զ����ƶ���ʽ��
    if(NULL == fp)
    {
		printf("File is opened failure!\n");
        return FALSE;
    }
    //��ȡ����
    fread(&bmpFileHeader,sizeof(BITMAPFILEHEADER),1,fp);
    fread(&bmpInfoHeader,sizeof(BITMAPINFOHEADER),1,fp);
    pBmpData = new unsigned char[bmpInfoHeader.biSizeImage];   //����ռ䣬��СΪλͼ���ݴ�С
    fread(pBmpData,sizeof(unsigned char),bmpInfoHeader.biSizeImage,fp);
    fclose(fp);            //��Ҫ���˹ر��ļ�
    return TRUE;
}
/**
* ������: convert
* ��  ��: ʵ��24λ���ɫͼ���Ҷ�ͼ��ת��
*/
unsigned char** convert()
{
    int k = 0,j,i;
    //��Ϊת������˸���ɫ������Ҫ�ı�
    bmpFileHeader.bfOffBits += (sizeof(RGBQUAD) * 256); 
     //biSizeImg�洢��Ϊλͼ����ռ�õ��ֽ�����ת��Ϊ�Ҷ�ͼ���ֵ�����ı䣬
    //��Ϊ24Ϊ���ɫλͼ���ݵ�һ��������3���ֽڱ�ʾ���Ҷ�ͼ��Ϊ1���ֽ�
    bmpInfoHeader.biBitCount = 8;
    int lineBytes = (bmpInfoHeader.biWidth * 8 + 31) / 32 * 4;
    int oldSize = bmpInfoHeader.biSizeImage;        //ԭͼ���ݴ�С
    bmpInfoHeader.biSizeImage = lineBytes * bmpInfoHeader.biHeight;
    //����Ҷ�ͼ�����ɫ��
    pColorTable = new RGBQUAD[256];
    for(i = 0; i < 256; i++ )
    {
        (*(pColorTable + i)).rgbBlue = i;
        (*(pColorTable + i)).rgbGreen = i;
        (*(pColorTable + i)).rgbRed = i;
        (*(pColorTable + i)).rgbReserved = 0;
    }
    //��RGBת��Ϊ�Ҷ�ֵ
    int red,green,blue;
	
    BYTE gray;
    pGrayData = new unsigned char[bmpInfoHeader.biSizeImage];
    memset(pGrayData,(BYTE)255,bmpInfoHeader.biSizeImage);
	
	for( j = 0; j < oldSize; j += 3 )
	{
		 red = *(pBmpData + j );
		green = *(pBmpData + j + 1);
		blue = *(pBmpData + j + 2);
					/*gray = (BYTE)((77 * red + 151 * green + 28 * blue) >> 8);*/
		gray = (BYTE)red;
		*(pGrayData + k++) = gray;
     }
    //һά����ת��Ϊ��ά    
	GrayMatrix =	(unsigned char**)malloc(sizeof(unsigned char*)*bmpInfoHeader.biHeight);
	for(i = 0;i<bmpInfoHeader.biHeight;i++)
	{
		GrayMatrix[i] = (unsigned char*)malloc(sizeof(unsigned char)*bmpInfoHeader.biWidth);
	}

	for(i = 0;i<bmpInfoHeader.biHeight;i++)
	{
		for(j = 0;j<bmpInfoHeader.biWidth;j++)
		{
			GrayMatrix[bmpInfoHeader.biHeight-1-i][j] = pGrayData[i*bmpInfoHeader.biWidth+j];
		}
	}
	return GrayMatrix;
}
/**
* ������: writeBmp
* ��  ��: fileName -- ת��֮����ļ���
* ��  ��: ��ת�����ͼ����Ϣд�뵽fileName�ļ���
*/
bool writeBmp(char *fileName,unsigned char **GrayMatrix)
{
	int i,j;
    FILE *fp = fopen(fileName,"wb");   //�Զ�����д��ʽ��
    if(NULL == fp)
    {
		printf("File is opened failure!");
        return FALSE;
    }
	//��ά����ת��Ϊһά
	for(i = 0;i<bmpInfoHeader.biHeight;i++)
	{
		for(j = 0;j<bmpInfoHeader.biWidth;j++)
		{
			pGrayData[i*bmpInfoHeader.biWidth+j] = GrayMatrix[i][j];
		}
	}
    //д������
    fwrite(&bmpFileHeader,sizeof(BITMAPFILEHEADER),1,fp);
    fwrite(&bmpInfoHeader,sizeof(BITMAPINFOHEADER),1,fp);
    fwrite(pColorTable,sizeof(RGBQUAD),256,fp);
	for(i = 0;i<bmpInfoHeader.biHeight;i++)
	{
		for(j = 0;j<bmpInfoHeader.biWidth;j++)
		{
			pGrayData[i*bmpInfoHeader.biWidth+j] = GrayMatrix[bmpInfoHeader.biHeight-1-i][j];
		}
	}
    fwrite(pGrayData,sizeof(unsigned char),bmpInfoHeader.biSizeImage,fp);
    fclose(fp);

    return TRUE;
}
/**
* ������:	Gray2Binary
* ��  ��:	���Ҷ�ͼת����0��255�Ķ�ֵͼ
* ����������Ҷ�ͼ��ά����ת����ֵ
* ���������ת����Ķ�ά����*/
BYTE** Gray2Binary(BYTE** gr,int threshold)
{
	int i,j;
	BYTE** bi;
	bi =	(unsigned char**)malloc(sizeof(unsigned char*)*bmpInfoHeader.biHeight);
	for(i = 0;i<bmpInfoHeader.biHeight;i++)
	{
		bi[i] = (unsigned char*)malloc(sizeof(unsigned char)*bmpInfoHeader.biWidth);
	}
	for(i = 0;i<bmpInfoHeader.biHeight;i++)
	{
		for(j = 0;j<bmpInfoHeader.biWidth;j++)
		{
			gr[i][j]>threshold?bi[i][j]=255:bi[i][j]=0;
		}
	}
	return bi;
}

/**
* ������: freeMatrix
* ��  ��: ��Ҫfree�ľ���,bmpInfoHeader.biHeight*bmpInfoHeader.biWidth
* ��  ��: ����̬���ٵĿռ��ͷ�
*/
void freeMatrix(unsigned char **Matrix){
	for (int i = 0;i<bmpInfoHeader.biHeight;i++)
	{
		free(Matrix[i]);
	}
	free(Matrix);
}
/**
* ������: work
* ��  ��: ��Ҫ������ֱ����������Ӽ���
*/
void work()
{	
	BYTE** GM,**BI;//GM���ҶȾ���BI����ֵ����
	char readFileName[50];
	char writeFileName[50];
	printf("������Ҫ�����ͼƬ·����\n");
	gets(readFileName);
    if(!readBmp(readFileName))
		printf("The function of readBmp error!");

    GM = convert();
	BI = Gray2Binary(GM,70);   //��ֵ70�Լ��޸�

	printf("������Ҫ����ĻҶ�ͼ·����\n");
	gets(writeFileName);
    if(!writeBmp(writeFileName,GM))
        printf("The function of writeBmp error!");
	else{
		freeMatrix(GM);
	}

	printf("������Ҫ����Ķ�ֵͼ·����\n");
	gets(writeFileName);
    if(!writeBmp(writeFileName,BI))
        printf("The function of writeBmp error!");
	else{
		freeMatrix(BI);
	}
 }
int main()
{
    work();
    //�ͷ��ڴ�ռ�
    delete []pColorTable;
    delete []pBmpData;
    delete []pGrayData;
	system("pause");
    return 0;
}