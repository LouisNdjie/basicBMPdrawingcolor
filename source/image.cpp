#include<iostream>
#include<fstream>
#include <limits>
#include"../header/image.h"

using namespace std;

void create_image(BMP_Header &info, BMP_DIB &head, Matrix_Color  pixel[], int height, int width)
{
    #pragma pack(1)
    std::FILE * f_out = std::fopen("image.bmp", "wb");

    if (f_out != NULL)
    {
        std::fwrite(&info, sizeof(BMP_Header), 1, f_out);
        std::fwrite(&head, sizeof(BMP_DIB), 1, f_out);
        std::fwrite(pixel, sizeof(Matrix_Color), width * height, f_out);
    }
}
// ---------------------------------------------------------------------------------------------------------
void put_pixel(Matrix_Color pixel[],int width, int height,Matrix_Color color, Point dot_position)
{
    if (dot_position.x < width && dot_position.y < height)
    {
        pixel[dot_position.y * width + dot_position.x] = color;
    }else
    {
        std::cout << " ce point ne peut pas etre place";
    }
}
// ---------------------------------------------------------------------------------------------------------
void draw_line(Matrix_Color pixel[],Matrix_Color line_color, Point start, Point fin, int width, int height)
{
    if(start.x < width && start.y < height && fin.x < width && fin.y < height)
    {
        if(start.x > fin.x || start.y > fin.y)
        {
            Point swap;
            swap.x = start.x;
            swap.y = start.y;
            
            start.x = fin.x;
            start.y = fin.y;

            fin.x = swap.x;
            fin.y = swap.y;
        }
        int dx = fin.x - start.x;
        int dy = fin.y - start.y;
        int er_in = (2*dy) - dx;
        int x = start.x;
        int y = start.y;

        for( x = start.x; x <= fin.x; x++)
        {
            pixel[y * width + x] = line_color;
            if(er_in > 0)
            {
                y++;
                er_in = er_in + (2*dy) - (2*dx);
            }else
            {
                er_in = er_in + (2*dy);
            }
        }
    
    }else
    {
        std::cout << " pas possible de tracer cette ligne";
    }
}
// ---------------------------------------------------------------------------------------------------------
void draw_square(Matrix_Color pixel[], Matrix_Color square_color, Point first_position, int height, int width, int square_size)
{
    if(first_position.x < width && first_position.y < height)
    {
        for(int i = first_position.y; i < square_size+first_position.y; i++)
        {
            for(int j = first_position.x; j < square_size+first_position.x; j++)
            {
                pixel[i * width + j] = square_color;
            }
        }
    }else
    {
        std::cout << "ce carre ne pourra pas etre represente";
    }
}
// ---------------------------------------------------------------------------------------------------------
void draw_rectangle(Matrix_Color pixel[], Matrix_Color rectangle_color, Point position, int longueur, int largeur, int width, int height)
{
    if(position.x < width && position.y < height)
    {
        for(int i = position.y; i <= largeur+position.y; i++)
        {
            for(int j = position.x; j <= longueur+position.x; j++)
            {
                pixel[i * width + j] = rectangle_color;
            }
        }
    }else
    {
        std::cout << "ce rectangle ne pourra pas etre represente";    
    }
    
}
// ---------------------------------------------------------------------------------------------------------
void draw_triangle(Matrix_Color pixel[], Matrix_Color triangle_color,Point pos, int hauteur,int width, int height)
{
    if(pos.x < width && pos.y < height)
    {
        for (int i = 0; i < hauteur; i++) {
        int y = pos.y - i;
        if (y < 0 || y >= height) continue;  
        
        int startX = pos.x + (hauteur - i - 1);
        
            for (int k = 0; k < 2 * i + 1; k++) {
            int x = startX + k;
                if (x >= 0 && x < width) {  
                    pixel[y * width + x] = triangle_color;
                }
            }
        }
    }else
    {
        std::cout << "ce triangle ne pourra pas etre represente";    
    }
}
// ---------------------------------------------------------------------------------------------------------
void draw_circle(Matrix_Color pixel[], Matrix_Color circle_color, Point center, int rayon, int width, int height)
{
    if(center.x < width && center.y < height && rayon < width)
    {
        int bas_circle = center.y - rayon;
        int haut_circle = center.y + rayon;
        int gauche_circle = center.x - rayon;
        int droite_circle = center.x + rayon;

        for(int y = bas_circle; y <= haut_circle; y++)
        {
          for(int x = gauche_circle; x <= droite_circle; x++)
          {
              int compo_x = x-center.x;
              int compo_y = y-center.y;

              int position =(compo_x * compo_x) + (compo_y * compo_y);

              if(position <= (rayon * rayon))
              {
                  pixel[y*width+x] = circle_color;
              }
          }
        }
    } 
}
// ---------------------------------------------------------------------------------------------------------
int readInt() {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Entrée invalide. Veuillez entrer un entier : ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        return value;
        }
    }
}
// ---------------------------------------------------------------------------------------------------------
void draw_hollow_square(Matrix_Color pixel[], Matrix_Color hollow_square_color, Point hollow_square_position, int hollow_square_size, int width, int height)
{
    if(hollow_square_position.x < width && hollow_square_position.y < height)
    {
       for(int i = hollow_square_position.x; i < hollow_square_size+hollow_square_position.x; i++)
       {
            if(hollow_square_position.y < height && i < width)
            {
                pixel[hollow_square_position.y * width+i] = hollow_square_color;
            }
            
            if(hollow_square_position.y+hollow_square_size-1< height && i < width)
            {
                pixel[(hollow_square_position.y+hollow_square_size-1) * width+i] = hollow_square_color;
            }
        }


       for(int i = hollow_square_position.y; i < hollow_square_size+hollow_square_position.y; i++)
        {
            if(hollow_square_position.x< width && i < height)
            {
                pixel[i* width+hollow_square_position.x] = hollow_square_color;
            }

            if(hollow_square_position.x+hollow_square_size-1< width && i < height)
            {
                pixel[i* width+(hollow_square_position.x + hollow_square_size-1)] = hollow_square_color;
            }
       }
       
    }else
    {
        std::cout << "ce carre ne pourra pas etre represente";
    }
}
// ---------------------------------------------------------------------------------------------------------
void draw_hollow_rectangle(Matrix_Color pixel[], Matrix_Color hollow_rectangle_color, Point hollow_rectangle_position, int hollow_rectangle_longueur, int hollow_rectangle_largeur, int width, int height)
{
    if(hollow_rectangle_position.x < width && hollow_rectangle_position.y < height)
    {
        for(int i = hollow_rectangle_position.x; i < hollow_rectangle_longueur+hollow_rectangle_position.x; i++)
       {
            if(hollow_rectangle_position.y < height && i < width)
            {
                pixel[hollow_rectangle_position.y * width+i] = hollow_rectangle_color;
            }
            
            if(hollow_rectangle_position.y+hollow_rectangle_largeur-1< height && i < width)
            {
                pixel[(hollow_rectangle_position.y+hollow_rectangle_largeur-1) * width+i] = hollow_rectangle_color;
            }
        }


       for(int i = hollow_rectangle_position.y; i < hollow_rectangle_largeur+hollow_rectangle_position.y; i++)
        {
            if(hollow_rectangle_position.x< width && i < height)
            {
                pixel[i* width+hollow_rectangle_position.x] = hollow_rectangle_color;
            }

            if(hollow_rectangle_position.x+hollow_rectangle_longueur-1< width && i < height)
            {
                pixel[i* width+(hollow_rectangle_position.x + hollow_rectangle_longueur-1)] = hollow_rectangle_color;
            }
       }
    }else
    {
        std::cout << "ce rectangle ne pourra pas etre represente";    
    }
       
}
// ---------------------------------------------------------------------------------------------------------
void draw_hollow_triangle(Matrix_Color pixel[], Matrix_Color hollow_triangle_color,Point hollow_triangle_pos, int hollow_triangle_hauteur,int width, int height)
{
    if(hollow_triangle_pos.x < width && hollow_triangle_pos.y < height)
    {
        for (int i = 0; i < hollow_triangle_hauteur; i++) {
        int y = hollow_triangle_pos.y - i;
        if (y < 0 || y >= height) continue;  
        
        int startX = hollow_triangle_pos.x + (hollow_triangle_hauteur - i - 1);
        
            if (i == 0) {
                if (startX >= 0 && startX < width) {
                    pixel[y * width + startX] = hollow_triangle_color; // Point supérieur
                }
            } else {
                int leftX = startX;
                int rightX = startX + 2 * i;
                if (leftX >= 0 && leftX < width) {
                    pixel[y * width + leftX] = hollow_triangle_color; 
                }
                if (rightX >= 0 && rightX < width) {
                    pixel[y * width + rightX] = hollow_triangle_color; 
                }
            }

            int base = hollow_triangle_pos.y - hollow_triangle_hauteur+1;
            if(base >= 0 && base < height)
            {
                int debut_base = hollow_triangle_pos.x;
                int fin_base = hollow_triangle_pos.x + 2 * (hollow_triangle_hauteur-1);
                for(int j = debut_base; j <= fin_base; j++)
                {
                    if(j > 0 && j < width)
                    {
                        pixel[base*width+j] = hollow_triangle_color;
                    }
                }
            }
        }
    }else
    {
        std::cout << "ce triangle ne pourra pas etre represente";    
    }

}
// ---------------------------------------------------------------------------------------------------------
void draw_circle(Matrix_Color pixel[], Matrix_Color hollow_circle_color, Point hollow_circle_center, int hollow_circle_rayon, int width, int height)
{
    if(center.x < width && center.y < height && rayon < width)
    {
        int bas_circle = center.y - rayon;
        int haut_circle = center.y + rayon;
        int gauche_circle = center.x - rayon;
        int droite_circle = center.x + rayon;

        for(int y = bas_circle; y <= haut_circle; y++)
        {
          for(int x = gauche_circle; x <= droite_circle; x++)
          {
              int compo_x = x-center.x;
              int compo_y = y-center.y;

              int position =(compo_x * compo_x) + (compo_y * compo_y);

              if(position == (rayon * rayon))
              {
                  pixel[y*width+x] = circle_color;
              }
          }
        }
    } 
}
