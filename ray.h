#ifndef RAY_H
#define RAY_H
#include "vec3.h"


class Ray
{
public:
    Ray();
    Ray(const Vec3& a, const Vec3& b);
    Vec3 origin() const;
    Vec3 direction() const;
    Vec3 point_at_parameter(double t) const;

    Vec3 a;
    Vec3 b;
};

#endif // RAY_H
