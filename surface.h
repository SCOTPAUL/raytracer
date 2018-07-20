#ifndef SURFACE_H
#define SURFACE_H

#include "ray.h"

class Material;

struct HitRecord
{
    double t;
    Vec3 p;
    Vec3 normal;
    Material *m_ptr;
};

class Surface
{
public:
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
};

#endif // SURFACE_H
