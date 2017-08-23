/*
 * pixelFunction.cpp
 *
 *  Created on: 2014年12月19日
 *      Author: kohill
 *      版权没有，欢迎仿冒
 */

#include <cstddef>
#include <stdint.h>
#include <iostream>
#include <windows.h>

/*图像的坐标*/
typedef struct {
	uint32_t x;
	uint32_t y;
} Coordinate;


/*
 * @Function: findStartPixel
 * @Description:寻找开始点的坐标
 * @param：
 * @return： 成功返回传入的坐标数组的首地址，否则为NULL
 * @Call：无
 */
Coordinate *findStartPixel(Coordinate thumbFlag[], byte **image, uint32_t width,
		uint32_t heigth, uint32_t xStart, uint32_t yStart = 0) {
	assert((image!=NULL)&&(xStart<=width)&&(yStart<=heigth));
	assert((image!=NULL)&&(xStart!=0)&&(yStart!=0));
	for (uint32_t k = 0, j = xStart + 1; j < width - 1; j++) {
		for (uint32_t i = yStart + 1; i < heigth - 1; i++) {
			if ((image[i][j]) + (image[i - 1][j]) + (image[i][j - 1])
					+ (image[i - 1][j - 1]) + (image[i + 1][j])
					+ (image[i][j + 1]) + (image[i + 1][j + 1])
					+ (image[i + 1][j - 1]) + (image[i - 1][j + 1]) < 255 * 3) {
				thumbFlag[k].x = j;
				thumbFlag[k].y = i;
				k++;
				if (k == 4) {
					return thumbFlag;
				}
				i += 100;
			}
		}
	}
	return NULL;
}
/*
 * @Function: markPiexl
 * @Description:以参考坐标为基准，寻找附近的黑色像素点
 * @param：
 * @Call：无
 * @return： 成功返回传入的二维数组，否则返回NULL
 */
byte** markPiexl(byte **image, uint32_t width, uint32_t heigth,Coordinate &start) {
	assert((image!=NULL)&&(&start!=NULL));
	assert((start.y<heigth)&&(start.x<width));
	uint32_t x= start.x;
	uint32_t y= start.y;
	for(uint32_t j=x-400;(j<x+800)&&(j<width);j++){
		for(uint32_t i=y-20;(i<y+20)&&(i<heigth);i++){
			if(image[i][j]==0){
				image[i][j]=1;
			}
		}
	}
	return image;
}
/*
 * @Function: clearPiexl
 * @Description:根据数组的标志（1）,清除其余像素点
 * @param：
 * @return： 成功返回传入的二维数组，否则返回NULL
 * @Call：无
 */
byte** clearPiexl(	byte **image, uint32_t width, uint32_t heigth){
	assert(image!=NULL);
	for(uint32_t i=0;i<heigth;i++){
		for(uint32_t j=0;j<width;j++){
			if(image[i][j]!=1){
				image[i][j]=255;
			}
		}
	}
	return image;
}
/*
 * @Function: pixelRecognize
 * @Description:本文件中的其他函数，以识别图像中的指缝
 * @param：
 * @return： 成功返回传入的二维数组，否则返回NULL
 * @Call：findStartPixel, markPiexl,clearPiexl
 */
byte** pixelRecognize(byte **image, uint32_t width, uint32_t heigth,
		uint32_t xStart, uint32_t yStart = 0) {
	/*获取坐标	 */
	assert((image!=NULL)&&(xStart<=width)&&(yStart<=heigth));
	assert((image!=NULL)&&(xStart!=0)&&(yStart!=0));
	Coordinate thumbFlag[4];
	findStartPixel(thumbFlag, image, width, heigth, xStart, yStart);
	markPiexl(image,width,heigth,thumbFlag[0]);
	markPiexl(image,width,heigth,thumbFlag[1]);
	markPiexl(image,width,heigth,thumbFlag[2]);
	markPiexl(image,width,heigth,thumbFlag[3]);
	clearPiexl(image,width,heigth);
	return image;
}

