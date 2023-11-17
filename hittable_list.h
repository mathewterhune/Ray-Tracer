#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
    
    /*
    shared pointer type is a pointer alloected type, with reference counting semantics.
        Every time you assign its avlue to another shared pointer the reference count is incremeneted,
        as shared pointers go out of scope (like at the end of a block or function) the reference count is decremented

    So,
        Once that count goes to zero, the object is safely deleted.

        make_shared<thing>(thing_constructor_params .. ) allocates a new instance of type thing

    Shared pointers allow  multiple geometires to share a common instance and it makes memory management automatic and easier to reason about

     "using" statement tell the compiler that we'll be getting shared_ptr and make_shared from the std library so we dont 
     need to prefix std:: every time
    
    */
    
    public:
        std::vector<shared_ptr<hittable>> objects;

        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) { add(object); }

        void clear() { objects.clear(); }
        void add(shared_ptr<hittable> object){
            objects.push_back(object);
        }

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            hit_record temp_rec;

            bool hit_anything = false;
            auto closest_so_far = ray_t.max;

            for (const auto& object : objects) {
                if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)){
                    hit_anything = true;
                    closest_so_far = temp_rec.t;
                    rec = temp_rec;
                }
            }
            return hit_anything;

        }
        
};


#endif