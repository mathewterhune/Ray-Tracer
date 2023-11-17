#ifndef HITTABLE_H
#define HITTABLE_H


#include "rtweekend.h"

class material; // tell the compiler that material is a class which will be defined later.

class hit_record {
    public:
        point3 p; // the 3D point that the was hit
        vec3 normal; // the normal towards the point which was hit?
        double t; // the t value which gives you the hit
        shared_ptr<material> mat;
        bool front_face; // Decided that the normals always point against the ray, so we need to store the information.

        void set_face_normal(const ray& r, const vec3& outward_normal) {
            // sets the hit record normal vector
            // NOTE: the parameter 'outward_normal' is assumed to have unit length.

            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }

};


class hittable {
    public:
        // virtual functions = member function which is expected to be redefined in derived classes
        virtual ~hittable() = default;

        virtual bool hit(const ray& r, interval ray_t, hit_record& rec) const = 0;
};

#endif