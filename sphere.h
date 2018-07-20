#ifndef SPHERE_H
#define SPHERE_H

#include "surface.h"

class Sphere : public Surface
{
public:
    Sphere();
    Sphere(Vec3 center, double r);
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const;
    Vec3 center;
    double radius;
};

#endif // SPHERE_H
