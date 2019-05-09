#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct Color {
    float R,G,B;
    Color () : R(1.0),G(1.0),B(1.0) {}
    Color(float red,float green,float blue)
        : R(red), G (green),B(blue) {}

};

#endif // COLOR_H_INCLUDED
