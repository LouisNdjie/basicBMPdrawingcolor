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

    while(running)
    {      
        
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
                        
                        case 3: //dessiner le carre
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
                        
                        case 4: //dessiner le rectangle
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
                        
                        case 5: //dessiner le triangle
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
                        
                        case 6: //dessiner le cercle
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