#include "bmpHEADER.h"

#define LineByte(width, bitCount)          ((width * bitCount + 31) / 32 * 4)
#define PaletteSize(biClrUsed, biBitCount) ((biClrUsed) ? (biClrUsed) : 1 << (biBitCount))

typedef struct
{
    BITMAPFILEHEADER    header;
    BITMAPINFOHEADER    infoHeader;
    PALETTE             palette;
    BYTE*               data;
} bmp_HL;

// 从文件中读取bmp图像，返回一个bmp_HL结构体
bmp_HL bmpRead(const char* filename);

// 将bmp图像写入文件
void bmpWrite(const char* filename, bmp_HL bmp);

// 释放bmp_HL结构体占用的内存
void bmpDelete(bmp_HL* bmp);

// 将24位真彩色图像转换为8位灰度图像
bmp_HL bmp_24to8_gray(bmp_HL bmp);

// 将8位灰度图像转换为反色8位灰度图像
bmp_HL bmp_8_graytoinvert_gray(bmp_HL bmp);