#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <iostream>

using color = vec3;


void write_color(std::ostream &out, color pixel_color, int samples_per_pixel){
    // Write the translated [0,255] value of each color component.

    // the colours of each rgb value 
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // divide the colour by the number of samples
    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    //  object of the class interval where the constructor takes in min(+infinity), max(-infinity)
    static const interval intensity(0.000,0.999);


    out << static_cast<int>(256 * intensity.clamp(r)) << ' ' << static_cast<int>(256 * intensity.clamp(b)) << ' ' << static_cast<int>(256 * intensity.clamp(g)) << '\n';
}


#endif 