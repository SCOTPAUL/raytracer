#ifndef MATERIAL_H
#define MATERIAL_H

#include "ray.h"
#include "surface.h"

class Material
{
public:
    Material();
    virtual bool scatter(const Ray& r_in, const HitRecord& hr, Vec3& attenuation, Ray& scattered) const = 0;
};

#endif // MATERIAL_H
