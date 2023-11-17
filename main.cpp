#include "rtweekend.h"

#include "camera.h"
#include "color.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

int main() {

    // World
    hittable_list world;

    auto material_ground = make_shared<lambertian>(color(0.8,0.8,0.3));

    // auto material_center = make_shared<lambertian>(color(0.2,0.0,0.0));
    // auto material_center2 = make_shared<lambertian>(color(1.0,1.0,1.0));
    auto material_center3 = make_shared<lambertian>(color(0.0,0.4,3.0));
    

    // auto material_left = make_shared<metal>(color(1.8,0.6,0.2));
    // auto material_right = make_shared<metal>(color(0.8,1.6,0.2));


    auto outside = make_shared<metal>(color(0.2,0.3,0.4));
    auto inside = make_shared<metal>(color(0.0,0.0,0.25));
    auto inside2 = make_shared<metal>(color(0.0,0.25,0.0));
    auto inside3 = make_shared<metal>(color(0.25,0.0,0.0));


    // center(x,y,z), radius , material 
    world.add(make_shared<sphere>(point3(0.0,-100.5,-1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3(0.0,0.0,-1.0), 0.5, outside));
    world.add(make_shared<sphere>(point3(0.25,0.0,-1.0),0.5, inside));
    world.add(make_shared<sphere>(point3(-0.25,0.0,-1.0),0.5, inside2));
    world.add(make_shared<sphere>(point3(0.0,0.0,-1.25),0.5, inside3));

    world.add(make_shared<sphere>(point3(0.0,0.0,-0.5),0.2, inside3));

    
    
    // world.add(make_shared<sphere>(point3(0.0,0.0,-1.0), 0.5, material_center));
    // world.add(make_shared<sphere>(point3(0.0,0.4,-1.0), 0.5, material_center2));
    // world.add(make_shared<sphere>(point3(0.0,0.5,-1.0), 0.5, material_center3));


    // world.add(make_shared<sphere>(point3(-1.0,0.0,-2.0), 0.6, material_left));
    // world.add(make_shared<sphere>(point3(1.0,0.0,-2.0), 0.9, material_right));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0; 
    cam.image_width = 400;
    cam.samples_per_pixel = 100; 
    cam.max_depth = 50; // maximum depth that the recursion can go into

    cam.render(world);
}