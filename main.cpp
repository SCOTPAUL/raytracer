#include <iostream>
#include <random>
#include "vec3.h"
#include "ray.h"
#include "math.h"
#include "float.h"
#include "surface.h"
#include "sphere.h"
#include "surfacelist.h"
#include "camera.h"

using namespace std;


Vec3 color(const Ray& r, SurfaceList world){
    HitRecord hr;

    if(world.hit(r, 1e-3, MAXFLOAT, hr)){
        Vec3 target = hr.p + hr.normal + random_in_unit_sphere();

        return 0.5 * color(Ray(hr.p, target - hr.p), world);
    }

    Vec3 unit_dir = r.direction().into_unit_vector();
    double t = 0.5 * (unit_dir.y() + 1.0);
    return (1.0 - t)*Vec3(1.0,1.0,1.0) + t*Vec3(0.5, 0.7, 1.0);
}



int main(){
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<> dist(0, 1);

    int nx = 1920;
    int ny = 1080;
    int ns = 30;

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";


    Camera cam = Camera();

    Surface *world[4];

    world[0] = new Sphere(Vec3(0,0,-1), 0.5);
    world[1] = new Sphere(Vec3(2,0.1,-1), 0.7);
    world[2] = new Sphere(Vec3(-1,-0.1,-2), 0.4);
    world[3] = new Sphere(Vec3(0,-100.5,-1), 100);

    SurfaceList sl = SurfaceList(world, 4);

    for(int j = ny - 1; j >= 0; j--){
        for(int i = 0; i < nx; i++){
            Vec3 col(0,0,0);

            for(int k = 0; k < ns; ++k){
                double u = double(i + dist(e2)) / double(nx);
                double v = double(j + dist(e2)) / double(ny);

                Ray r = cam.get_ray(u, v);
                col += color(r, sl);
            }

            col /= double(ns);
            col = Vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));

            int ir = int(255.99 * col.r());
            int ig = int(255.99 * col.g());
            int ib = int(255.99 * col.b());

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    return 0;
}
