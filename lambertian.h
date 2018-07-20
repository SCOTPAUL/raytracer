#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "material.h"

class Lambertian : public Material
{
public:
    Lambertian(const Vec3& a);
    virtual bool scatter(const Ray& r_in, const HitRecord& hr, Vec3& attenuation, Ray& scattered) const;
    Vec3 albedo;
};

#endif // LAMBERTIAN_H
