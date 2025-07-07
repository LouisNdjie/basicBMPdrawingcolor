#include<iostream>
#include<fstream>

// 
#pragma pack(1)
struct BMP_Header
{
    char typeBmp[2];
    int size ;
    int res1 : 16;
    int res2 : 16; 
    int offsetFrame;
};

struct BMP_DIB
{
    int headSize;
    signed int width;
    signed int height;
    int colorPlan : 16;
    int bitsPerPixel : 16;
    int compressMethod;
    int frameBuffer;
    int resH;
    int resV;
    int colorPalet;
    int importantColor;
};

struct Matrix_Color
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
    unsigned char _;
};

char type[2];

int main(void)
{

    const int width = 20;
    const int height = 16;

    const int sizeBuffer = width * height * sizeof(Matrix_Color);

    BMP_Header info = 
    {
        .typeBmp = {0x42, 0x4D},
        .size = sizeof(BMP_Header) + sizeof(BMP_DIB) + sizeBuffer,
        .res1  = 0,
        .res2  = 0,
        .offsetFrame = sizeof(BMP_Header) + sizeof(BMP_DIB)   
    };

    BMP_DIB head = 
    {
        .headSize = sizeof(BMP_DIB),
        .width = width,
        .height = height,
        .colorPlan = 1,
        .bitsPerPixel  = 8 * sizeof(Matrix_Color),
        .compressMethod = 0,
        .frameBuffer = sizeBuffer ,
        .resH = 2835,
        .resV = 2835,
        .colorPalet = 0,
        .importantColor = 0 
    };
    Matrix_Color *pixel = new Matrix_Color[width * height];

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            pixel[i + width + j].blue = 255;
            pixel[i + width + j].green = 255;
            pixel[i + width + j].red = 0;
           
        }
    }

    std::FILE * f_out = std::fopen("test.bmp", "wb");

    if (f_out != NULL)
    {
        std::fwrite(&info, sizeof(BMP_Header), 1, f_out);
        std::fwrite(&head, sizeof(BMP_DIB), 1, f_out);
        std::fwrite(pixel, sizeof(Matrix_Color), width * height, f_out);
    }

    delete[] pixel;

    return 0;
}