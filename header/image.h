#ifndef __BMPLIBRAIRY__
#define __BMPLIBRAIRY__

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

};

struct Point
{
    int x;
    int y;
};

// ----------------------------------------------------------------------------------
void create_image(BMP_Header &info, BMP_DIB &head, Matrix_Color pixel[], int width, int height);
void put_pixel(Matrix_Color pixel[],int width, int height,Matrix_Color color, Point dot_position);
void draw_line(Matrix_Color pixel[],Matrix_Color line_color, Point start, Point fin, int width, int height);
void draw_square(Matrix_Color pixel[], Matrix_Color square_color, Point first_position, int height, int width, int square_size);
void draw_rectangle(Matrix_Color pixel[], Matrix_Color rectangle_color, Point position, int longueur, int largeur, int width, int height);
void draw_triangle(Matrix_Color pixel[], Matrix_Color triangle_color,Point pos, int hauteur,int width, int height);
void draw_circle(Matrix_Color pixel[], Matrix_Color circle_color, Point center, int rayon, int width, int height);
void draw_hollow_square(Matrix_Color pixel[], Matrix_Color hollow_square_color, Point hollow_square_position, int hollow_square_size, int width, int height);
void draw_hollow_rectangle(Matrix_Color pixel[], Matrix_Color hollow_rectangle_color, Point hollow_rectangle_position, int hollow_rectangle_longueur, int hollow_rectangle_largeur, int width, int height);
void draw_hollow_triangle(Matrix_Color pixel[], Matrix_Color hollow_triangle_color,Point hollow_triangle_pos, int hollow_triangle_hauteur,int width, int height);
void draw_hollow_circle(Matrix_Color pixel[], Matrix_Color hollow_circle_color, Point hollow_circle_center, int hollow_circle_rayon, int width, int height);
int readInt();
#endif