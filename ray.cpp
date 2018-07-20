#include "ray.h"

Ray::Ray()
{

}

Ray::Ray(const Vec3& a, const Vec3& b) { this->a = a; this->b = b; }
Vec3 Ray::origin() const { return a; }
Vec3 Ray::direction() const { return b; }
Vec3 Ray::point_at_parameter(double t) const { return a + t*b; }
