#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
        ray() {}

        // constructor
        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}


        // Functions
        point3 origin() const { return orig; }
        vec3 direction() const { return dir; }

        
        point3 at(double t) const {
            return orig + t*dir;
        }

    private:
        point3 orig;
        point3 dir;
};

#endif