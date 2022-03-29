#ifndef COLOR
#define COLOR

// Am definit o structura pentru a definii culorile care urmeaza sa fie utilizate
//Modifica backgroundul si putin din culoarea fractalului in sine
//Pentru a schimba culoarea modificati valorile r g b din paranteze
//Atasez aici un site pentru valorile acestora in functie de culoarea dorita
//https://www.rapidtables.com/web/color/RGB_Color.html

struct Color
{
    //Valorile pot fi setate si pe 0 0 0.
    Color(): r(255), g(204), b(204) {}
    Color(double red, double green, double blue): r(red), g(green), b(blue) {}

    Color operator*(const double scale)
    {
      return Color(r*scale, g*scale, b*scale);
    }

    Color operator+(Color mix)
    {
      return Color( (r + mix.r)/2, (g + mix.g)/2, (b + mix.b)/2);
    }

    double r, g, b;
};
#endif
