#include<iostream>
#include<fstream>
#include<stdlib.h>
#include"header/menu.h"
#include"header/image.h"
#include <limits>

using namespace std;

int main(void)
{
    int choix = 0;

    bool running = true;
    
    int width = 0;
    int height = 0;
    

    presentation();

    print_main_menu();
    choix = readInt();
  
    while(running)
    {
        if(choix == 2)
        {
            return 0;
        }
        cout << "entrez les dimensions de l'image\nlargeur : ";
        width = readInt();
        cout << "hauteur : ";
        height = readInt();

        int sizeBuffer = width * height * sizeof(Matrix_Color);
    
 
    
        BMP_Header info = 
        {
            .typeBmp = {0x42, 0x4D},
            .size = int(sizeof(BMP_Header) + sizeof(BMP_DIB) + sizeBuffer),
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
        
        system("cls");
        char ajouter = 'Y';
        bool ajout_figure = false;
        int choice = 0;
        switch(choix)
        {
            case 1:
                ajout_figure = true;
                while(ajout_figure)
                {
                    gen_image_menu();
                    choice = readInt();;
                    system("cls");
                    switch(choice)
                    {
                        case 1:  // placer le point sur l'image
                            Point dot_position;
                            Matrix_Color dot_color;
                            
                            cout << "entrez les coordonnees du point\n abscisse :";
                            dot_position.x = readInt();
                            cout << "ordonne :";
                            dot_position.y = readInt();

                            cout << "entrez les nuances de couleurs des points\n rouge [0 ~ 255] :";
                            dot_color.red = readInt();
                            cout << "vert [0 ~ 255] :";
                            dot_color.green = readInt();
                            cout << " bleu [0 ~ 255] : ";
                            dot_color.blue = readInt();

                            put_pixel(pixel, width, height, dot_color, dot_position);
                            break;

                        case 2: // dessiner une ligne sur l'image
                            Point start, fin;
                            Matrix_Color line_color;
                        
                            cout << "entrez les coordonnees du point de debut\n abscisse :";
                            start.x = readInt();
                            cout << "ordonne :";
                            start.y = readInt();

                            cout << "entrez les coordonnees du point fin\n abscisse :";
                            fin.x = readInt();
                            cout << "ordonne :";
                            fin.y = readInt();

                            cout << "entrez les nuances de couleurs de la ligne \n rouge [0 ~ 255] :";
                            line_color.red = readInt();
                            cout << "vert [0 ~ 255] :";
                            line_color.green = readInt();
                            cout << " bleu [0 ~ 255] : ";
                            line_color.blue = readInt();
 
                            draw_line(pixel,line_color, start, fin, width, height);
                            break;
                        
                        case 3:
                        {
                            int typeOfSquare = 1;
                            full_or_empty();
                            typeOfSquare = readInt();
                            system("cls");
                            switch(typeOfSquare)
                            {
                                case 1: //carre plein
                                    Matrix_Color square_color;
                                    Point square_position;
                                    int square_size;
                                    
                                    cout << "entrez les coordonnees du point de positionnement du carre\n abscisse :";
                                    square_position.x = readInt();
                                    cout << "ordonne :";
                                    square_position.y = readInt();
                                    
                                    cout << "entrez les nuances de couleurs du carre \n rouge [0 ~ 255] :";
                                    square_color.red = readInt();
                                    cout << "vert [0 ~ 255] :";
                                    square_color.green = readInt();
                                    cout << " bleu [0 ~ 255] : ";
                                    square_color.blue = readInt();
                                    
                                    cout << "entrez la taille du carre : ";
                                    square_size = readInt();
                                    
                                    draw_square(pixel, square_color, square_position, height, width, square_size);
                            
                                    break;

                                case 2: // carre vide
                                    Matrix_Color hollow_square_color;
                                    Point hollow_square_position;
                                    int hollow_square_size;
                                    
                                    cout << "entrez les coordonnees du point de positionnement du carre\n abscisse :";
                                    hollow_square_position.x = readInt();
                                    cout << "ordonne :";
                                    hollow_square_position.y = readInt();
                                    
                                    cout << "entrez les nuances de couleurs du carre \n rouge [0 ~ 255] :";
                                    hollow_square_color.red = readInt();
                                    cout << "vert [0 ~ 255] :";
                                    hollow_square_color.green = readInt();
                                    cout << " bleu [0 ~ 255] : ";
                                    hollow_square_color.blue = readInt();
                                    
                                    cout << "entrez la taille du carre : ";
                                    hollow_square_size = readInt();
                                    
                                    draw_hollow_square(pixel, hollow_square_color, hollow_square_position, hollow_square_size, width, height);
                                    break;
                            }

                            break;
                        } //dessiner le carre
                            
                        
                        case 4:
                        {
                            int typeOfRectangle = 1;
                            full_or_empty();
                            typeOfRectangle = readInt();
                            system("cls");
                            switch(typeOfRectangle)
                            {
                                case 1: //rectangle plein
                                    int longueur, largeur;
                                    Point rectangle_position;
                                    Matrix_Color rectangle_color;

                                    cout << "entrez les coordonnees du point de positionnement du rectangle\n abscisse :";
                                    rectangle_position.x = readInt();
                                    cout << "ordonne :";
                                    rectangle_position.y = readInt();

                                    cout << "entrez les nuances de couleurs du rectangle \n rouge [0 ~ 255] :";
                                    rectangle_color.red = readInt();
                                    cout << "vert [0 ~ 255] :";
                                    rectangle_color.green = readInt();
                                    cout << " bleu [0 ~ 255] : ";
                                    rectangle_color.blue = readInt();

                                    cout << "entrez les dimensions du rectangle\n largeur:";
                                    largeur = readInt();
                                    cout << "longueur :";
                                    longueur = readInt();

                                    draw_rectangle(pixel, rectangle_color, rectangle_position, longueur, largeur, width, height);

                                    break;

                                case 2: // rectangle vide
                                int hollow_rectangle_longueur, hollow_rectangle_largeur;
                                    Point hollow_rectangle_position;
                                    Matrix_Color hollow_rectangle_color;

                                    cout << "entrez les coordonnees du point de positionnement du rectangle\n abscisse :";
                                    hollow_rectangle_position.x = readInt();
                                    cout << "ordonne :";
                                    hollow_rectangle_position.y = readInt();

                                    cout << "entrez les nuances de couleurs du rectangle \n rouge [0 ~ 255] :";
                                    hollow_rectangle_color.red = readInt();
                                    cout << "vert [0 ~ 255] :";
                                    hollow_rectangle_color.green = readInt();
                                    cout << " bleu [0 ~ 255] : ";
                                    hollow_rectangle_color.blue = readInt();

                                    cout << "entrez les dimensions du rectangle\n largeur:";
                                    hollow_rectangle_largeur = readInt();
                                    cout << "longueur :";
                                    hollow_rectangle_longueur = readInt();

                                    draw_hollow_rectangle(pixel, hollow_rectangle_color, hollow_rectangle_position, hollow_rectangle_longueur, hollow_rectangle_largeur, width, height);

                                    break;
                            }
                        break;    
                        } //dessiner le rectangle

                        case 5:
                        {
                            int typeOftriangle = 1;
                            full_or_empty();
                            typeOftriangle = readInt();
                            system("cls");
                            switch(typeOftriangle)
                            {
                                case 1: //triangle plein
                                    int hauteur;
                                    Point triangle_position;
                                    Matrix_Color triangle_color;

                                    cout << "entrez les coordonnees du point de positionnement du triangle\n abscisse :";
                                    triangle_position.x = readInt();
                                    cout << "ordonne :";
                                    triangle_position.y = readInt();


                                    cout << "entrez les nuances de couleurs du triangle\n rouge [0 ~ 255] :";
                                    triangle_color.red = readInt();
                                    cout << "vert [0 ~ 255] :";
                                    triangle_color.green = readInt();
                                    cout << " bleu [0 ~ 255] : ";
                                    triangle_color.blue = readInt();

                                    cout << "entrez la hauteur du triangle\n hauteur :";
                                    hauteur = readInt();

                                    draw_triangle(pixel, triangle_color, triangle_position, hauteur, width, height);
                                break;

                                case 2: // triangle vide
                                    int hollow_triangle_hauteur;
                                    Point hollow_triangle_pos;
                                    Matrix_Color hollow_triangle_color;

                                    cout << "entrez les coordonnees du point de positionnement du triangle\n abscisse :";
                                    hollow_triangle_pos.x = readInt();
                                    cout << "ordonne :";
                                    hollow_triangle_pos.y = readInt();


                                    cout << "entrez les nuances de couleurs du triangle\n rouge [0 ~ 255] :";
                                    hollow_triangle_color.red = readInt();
                                    cout << "vert [0 ~ 255] :";
                                    hollow_triangle_color.green = readInt();
                                    cout << " bleu [0 ~ 255] : ";
                                    hollow_triangle_color.blue = readInt();
                                    
                                    cout << "entrez la hauteur du triangle\n hauteur :";
                                    hollow_triangle_hauteur = readInt();

                                    draw_hollow_triangle(pixel, hollow_triangle_color, hollow_triangle_pos, hollow_triangle_hauteur, width, height);

                                    break;
                            }
                            break;
                        } //dessiner le triangle
                        
                        case 6: 
                            int typeOfCircle = 1;
                            full_or_empty();
                            typeOfCircle = readInt();
                            system("cls");
                            switch(typeOfCircle)
                            {
                                case 1: //cercle plein
                                    Matrix_Color circle_color;
                                    Point center; 
                                    int rayon;

                                    cout << "entrez les coordonnees du point de positionnement du centre du cercle\n abscisse :";
                                    center.x = readInt();
                                    cout << "ordonne :";
                                    center.y = readInt();

                                    cout << "entrez les nuances de couleurs du triangle\n rouge [0 ~ 255] :";
                                    circle_color.red = readInt();
                                    cout << "vert [0 ~ 255] :";
                                    circle_color.green = readInt();
                                    cout << " bleu [0 ~ 255] : ";
                                    circle_color.blue = readInt();

                                    cout << "entrez le taille du rayon\nrayon :";
                                    rayon = readInt();

                                    draw_circle(pixel, circle_color, center, rayon, width, height);

                                    break;

                                case 2: // cercle vide
                                    Matrix_Color hollow_circle_color;
                                    Point hollow_circle_center; 
                                    int hollow_circle_rayon;

                                    cout << "entrez les coordonnees du point de positionnement du centre du cercle\n abscisse :";
                                    hollow_circle_center.x = readInt();
                                    cout << "ordonne :";
                                    hollow_circle_center.y = readInt();

                                    cout << "entrez les nuances de couleurs du triangle\n rouge [0 ~ 255] :";
                                    hollow_circle_color.red = readInt();
                                    cout << "vert [0 ~ 255] :";
                                    hollow_circle_color.green = readInt();
                                    cout << " bleu [0 ~ 255] : ";
                                    hollow_circle_color.blue = readInt();

                                    cout << "entrez le taille du rayon\nrayon :";
                                    hollow_circle_rayon = readInt();

                                    draw_circle(pixel, hollow_circle_color, hollow_circle_center, hollow_circle_rayon, width, height);

                                    break;
                            }
                            break;
                        } //dessiner le cercle
                            
                    }
                    cout << "voulez-vous encore ajoutez une figure [Y-N] :";
                    cin >> ajouter;
                    if(ajouter == 'N')
                    {
                        ajout_figure = false;
                    }
                }
                break;
        }
        create_image(info, head, pixel, height, width);
        running = false;
        delete[] pixel;
    }
    
    return 0;
}