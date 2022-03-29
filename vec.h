#ifndef VEC_H
#define VEC_H
#include <cmath>
#define PI 3.14159265

// Initializare vector
struct Vec {
  double x, y;
  Vec(): x(0), y(0) {}
  Vec(double a, double b): x(a), y(b) {}

//Operatorul vec este un operator care transforma o matrice intr-o stiva verticala a coloanelor matricei
  Vec operator+(const Vec& p) {
    return Vec(x + p.x, y + p.y);
  }
  Vec operator-(const Vec& p) {
    return Vec(x - p.x, y - p.y);
  }

//Aceasta insereaza elementul specificat la pozitia specificata.
//Muta elementul aflat în acea pozitie (daca exista) si orice elemente ulterioare la dreapta (va adauga unul la indici).
  void add(const Vec& p) {
    x += p.x;
    y += p.y;
  }
//Functia este folosita pentru a inlocui sirul într-un vector.
  void sub(const Vec& p) {
    x -= p.x;
    y -= p.y;
  }
//Functia scale se foloseste pentru a centra si/sau scala coloanele unei matrice.
  void scale(double factor) {
    x = factor*x;
    y = factor*y;
  }
//Functia calculeaza marimea(sau lungimea) unui vector.
//Deoarece nu are o pozitie de pornire, marimea unui vector poate fi considerată ca distanta de la coordonata (0,0) la valoarea sa (x,y).
  float mag() {
    return sqrt(x*x + y*y);
  }
//Functia este utilizata pentru normalizarea unei imagini sau a unei matrice de intrare.
//Normalizarea este un proces pentru a aduce sau a readuce ceva la starea sau starea normala.
  void normalize() {
    float magnitudinea = mag();
    if(magnitudinea != 0) {
       scale(1/magnitudinea);
    }
  }

//Functia este folosita pentru a roti ordinea elementelor intr-un interval [primul, ultimul).
//Secventa va incepe la elementul din mijlocul secventei sursa si ultimul element va fi urmat de primul.
//mijloc la elementele dintre mijloc si ultimul element.
  Vec rotate(double grade) {
    double theta = (grade * PI / 180.0);
    double cosinus = cos(theta);
    double sinus = sin(theta);
    double a = x*cosinus - y*sinus;
    double b = x*sinus + y*cosinus;
    return Vec(a, b);
  }
// a si b sunt noile valori pentru x si y
};

#endif
