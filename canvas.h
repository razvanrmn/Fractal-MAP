#ifndef CANVAS_H
#define CANVAS_H
#include "color.h"
#include "vec.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

// Am folosit clasa Canvas pentru a putea desena
class Canvas {
public:
  Canvas(): latime(500), inaltime(500) {}

  int latime_fereastra() { return latime; }
  int inaltime_fereastra() { return latime; }

//Constructie imagine finala
  void creeareImagine(std::ofstream &out)
  {
    out << "P3\n" << latime << std::endl << inaltime << std::endl << "255\n" ;
        for(int i = 0; i < inaltime; ++i)
        {
            for(int j = 0; j < latime; ++j)
            {
                out << (int)pixel_col[i][j].r << std::endl;
                out << (int)pixel_col[i][j].g << std::endl;
                out << (int)pixel_col[i][j].b << std::endl;
            }
        }
  }

  // Aici am folosit algoritmul lui Bresenham pentru a desena o aproximare a liniilor
  // Calculeaza coordonatele pentru o linie aproximativa între doi vectori de pe imagine si populeaza matricea Canvas:pixel_col

  void creeareForma(Vec startP, Vec endP, double lungimea_liniei)
  {
    const bool panta = fabs(endP.y - startP.y) > fabs(endP.x - startP.x);
    // startP: Incepe vectorul
    // endP  : Sfarsit vector
    // lungimea_liniei : lungimea liniei
    // panta : coeficient unghiular
    //Functia fabs() ia un singur argument (in double) si returneaza valoarea absoluta a acelui numar (tot in double).

    if(panta)
    {
      std::swap(startP.x, startP.y);
      std::swap(endP.x, endP.y);
    }

    if(startP.x > endP.x)
    {
      std::swap(startP.x, endP.x);
      std::swap(startP.y, endP.y);
    }

    //Am declarat axele dx si dy de tip float si le-am atribuit valori
    double dy = fabs(endP.y - startP.y);
    double dx = (endP.x - startP.x);

    float eroare = dx / 2.0f;
    const int pasi = (startP.y < endP.y) ? 1 : -1;
    int mijlocY = (int)startP.y;

    const int maxim = (int)endP.x;
        for(int x=(int)startP.x; x<maxim; ++x)
        {
            if(panta)
            {
                pixel_col[mijlocY][x].g = lungimea_liniei *255;
                pixel_col[mijlocY][x].b = lungimea_liniei *200;
            }
                else
                {
                    pixel_col[x][mijlocY].g = lungimea_liniei *255;
                    pixel_col[x][mijlocY].b = lungimea_liniei *200;
                }

      eroare -= dy;
        if(eroare < 0)
        {
          mijlocY += pasi;
          eroare += dx;
        }
    }
  }
// Aici am declarat o clasa privata deoarece aveam nevoie de aceste variabile doar in canvas.h
private:
  int latime;
  int inaltime;
  Color pixel_col[500][500];
};

#endif
