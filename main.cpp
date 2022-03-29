#include <fstream>
#include <iostream>
#include <cmath>
#include "canvas.h"
using namespace std;
//Am creeat o functie care creeaza copacul final
//In aceasta functie am apelat functiile pe care le-am creeat in canvas.h de aceea am inclus libraria in main
void creeareCopac(Canvas &canv, Vec radacinaA, Vec radacinaB, const double unghi )
{
    Vec directie = radacinaB - radacinaA;
    int magnitudine = directie.mag();
    if(magnitudine < 5) return;
    canv.creeareForma(radacinaA, radacinaB, magnitudine);
    directie.scale(0.75);
    Vec dreapta = directie.rotate(unghi);
    Vec stanga = directie.rotate(-1 * unghi);
    creeareCopac(canv, radacinaB, dreapta + radacinaB, unghi);
    creeareCopac(canv, radacinaB, stanga + radacinaB, unghi );
}

int main()
{
  Canvas canvas;

  double grade = 50;
  //Pentru a modifica fractalul schimbati variabila grade (Puteti sa ii dati valori intre 1 si 50)

  const double latime = canvas.latime_fereastra();
  const double intaltime = canvas.inaltime_fereastra();

  Vec A(latime / 2, intaltime);
  Vec B(intaltime / 2, intaltime - 100);
  creeareCopac(canvas, A, B, grade);

  //Modificati partitia unde sa fie exportat fisierul final !!
  ofstream outfile("/Users/razvanrmn/Desktop/copaculDA.ppm");
  canvas.creeareImagine(outfile);
  outfile.close();
  return 0;
}
