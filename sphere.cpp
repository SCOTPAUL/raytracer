#include "sphere.h"
#include "vec3.h"
#include "surface.h"
#include "math.h"

Sphere::Sphere()
{

}

Sphere::Sphere(Vec3 center, double r): center(center), radius(r)
{

}

bool Sphere::hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const {
    Vec3 oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = dot(oc, r.direction());
    double c = dot(oc, oc) - radius * radius;
    double desc = b * b - a*c;

    if(desc > 0){
        double tmp = (-b - sqrt(desc)) / a;
        if(tmp < t_max && tmp > t_min){
            rec.t = tmp;
            rec.p = r.point_at_parameter(tmp);
            rec.normal = (rec.p - center) / radius;
            return true;
        }

        tmp = (-b + sqrt(desc)) / a;
        if(tmp < t_max && tmp > t_min){
            rec.t = tmp;
            rec.p = r.point_at_parameter(tmp);
            rec.normal = (rec.p - center) / radius;
            return true;
        }
    }

    return false;
}
