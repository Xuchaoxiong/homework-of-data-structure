#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1) 

typedef unsigned short WORD; //WORD代替unsigned short
typedef unsigned long DWORD;
typedef long LONG;
typedef unsigned char BYTE;
#define TRUE 1;
#define FALSE 0;

typedef struct tagBITMAPFILEHEADER { // bmfh 
	WORD bfType; // 位图文件的类型，必须为BM
	DWORD bfSize; // 图片的大小，以字节为单位，
	WORD bfReserved1; // 位图文件保留字，必须为0
	WORD bfReserved2; // 位图文件保留字，必须为0
	DWORD bfOffBits; // 位图数据的起始位置，以相对于位图文件头的偏移量表示，以字节为单位,54个字节
} BITMAPFILEHEADER; // BITMAPFILEHEADER代表一个结构体类型

typedef struct tagBITMAPINFOHEADER{ // bmih 
	DWORD biSize; // 本结构所占用字节数
	LONG biWidth; // 位图的宽度，以像素为单位
	LONG biHeight; // 位图的高度，以像素为单位
	WORD biPlanes; // 目标设备的级别，必须为1
	WORD biBitCount;// 每个像素所需的位数，必须是1(双色),4(16色)，8(256色)或24(真彩色)之一
	DWORD biCompression; // 位图压缩类型，必须是 0(不压缩),1(BI_RLE8压缩类型)或2(BI_RLE4压缩类型)之一
	DWORD biSizeImage; // 位图的大小，以字节为单位
	LONG biXPelsPerMeter; // 位图水平分辨率，每米像素数
	LONG biYPelsPerMeter; // 位图垂直分辨率，每米像素数
	DWORD biClrUsed;// 位图实际使用的颜色表中的颜色数
	DWORD biClrImportant;// 位图显示过程中重要的颜色数
} BITMAPINFOHEADER; 

typedef struct tagRGBQUAD{
	BYTE rgbBlue;//蓝色的亮度（值范围为0-255)
	BYTE rgbGreen;//绿色的亮度（值范围为0-255)
	BYTE rgbRed;//红色的亮度（值范围为0-255)
	BYTE rgbReserved;//保留，必须为0
}RGBQUAD;

BITMAPFILEHEADER bmpFileHeader; //位图文件头
BITMAPINFOHEADER bmpInfoHeader; //位图信息头
RGBQUAD *pColorTable;            //颜色表，注：24位真彩色图无颜色表
unsigned char *pBmpData;        //位图数据
unsigned char *pGrayData;        //灰度图像数据
unsigned char **GrayMatrix;	 //灰度图像数据二维矩阵

/**
* 函数名: readBmp
* 参  数: fileName -- 要转换的图片名
* 功  能: 读取fileName文件信息，读取成功返回TRUE，反之，返回FALSE
*/
bool readBmp(char *fileName)
{
    FILE *fp = fopen(fileName,"rb");    //以二进制读方式打开
    if(NULL == fp)
    {
		printf("File is opened failure!\n");
        return FALSE;
    }
    //读取数据
    fread(&bmpFileHeader,sizeof(BITMAPFILEHEADER),1,fp);
    fread(&bmpInfoHeader,sizeof(BITMAPINFOHEADER),1,fp);
    pBmpData = new unsigned char[bmpInfoHeader.biSizeImage];   //申请空间，大小为位图数据大小
    fread(pBmpData,sizeof(unsigned char),bmpInfoHeader.biSizeImage,fp);
    fclose(fp);            //不要忘了关闭文件
    return TRUE;
}
/**
* 函数名: convert
* 功  能: 实现24位真彩色图到灰度图的转换
*/
unsigned char** convert()
{
    int k = 0,j,i;
    //因为转换后多了个颜色表，所以要改变
    bmpFileHeader.bfOffBits += (sizeof(RGBQUAD) * 256); 
     //biSizeImg存储的为位图数据占用的字节数，转换为灰度图像后值发生改变，
    //因为24为真彩色位图数据的一个像素用3各字节表示，灰度图像为1个字节
    bmpInfoHeader.biBitCount = 8;
    int lineBytes = (bmpInfoHeader.biWidth * 8 + 31) / 32 * 4;
    int oldSize = bmpInfoHeader.biSizeImage;        //原图数据大小
    bmpInfoHeader.biSizeImage = lineBytes * bmpInfoHeader.biHeight;
    //定义灰度图像的颜色表
    pColorTable = new RGBQUAD[256];
    for(i = 0; i < 256; i++ )
    {
        (*(pColorTable + i)).rgbBlue = i;
        (*(pColorTable + i)).rgbGreen = i;
        (*(pColorTable + i)).rgbRed = i;
        (*(pColorTable + i)).rgbReserved = 0;
    }
    //将RGB转换为灰度值
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
    //一维矩阵转化为二维    
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
* 函数名: writeBmp
* 参  数: fileName -- 转换之后的文件名
* 功  能: 将转换后的图像信息写入到fileName文件中
*/
bool writeBmp(char *fileName,unsigned char **GrayMatrix)
{
	int i,j;
    FILE *fp = fopen(fileName,"wb");   //以二进制写方式打开
    if(NULL == fp)
    {
		printf("File is opened failure!");
        return FALSE;
    }
	//二维矩阵转换为一维
	for(i = 0;i<bmpInfoHeader.biHeight;i++)
	{
		for(j = 0;j<bmpInfoHeader.biWidth;j++)
		{
			pGrayData[i*bmpInfoHeader.biWidth+j] = GrayMatrix[i][j];
		}
	}
    //写入数据
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
* 函数名:	Gray2Binary
* 功  能:	将灰度图转换成0和255的二值图
* 输入参数：灰度图二维矩阵，转换阈值
* 输出参数：转换后的二维矩阵*/
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
* 函数名: freeMatrix
* 参  数: 需要free的矩阵,bmpInfoHeader.biHeight*bmpInfoHeader.biWidth
* 功  能: 将动态开辟的空间释放
*/
void freeMatrix(unsigned char **Matrix){
	for (int i = 0;i<bmpInfoHeader.biHeight;i++)
	{
		free(Matrix[i]);
	}
	free(Matrix);
}
/**
* 函数名: work
* 功  能: 主要处理步骤直接在这里添加即可
*/
void work()
{	
	BYTE** GM,**BI;//GM：灰度矩阵；BI：二值矩阵
	char readFileName[50];
	char writeFileName[50];
	printf("请输入要读入的图片路径：\n");
	gets(readFileName);
    if(!readBmp(readFileName))
		printf("The function of readBmp error!");

    GM = convert();
	BI = Gray2Binary(GM,70);   //阈值70自己修改

	printf("请输入要保存的灰度图路径：\n");
	gets(writeFileName);
    if(!writeBmp(writeFileName,GM))
        printf("The function of writeBmp error!");
	else{
		freeMatrix(GM);
	}

	printf("请输入要保存的二值图路径：\n");
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
    //释放内存空间
    delete []pColorTable;
    delete []pBmpData;
    delete []pGrayData;
	system("pause");
    return 0;
}