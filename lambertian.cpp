#include "lambertian.h"
#include <random>
using namespace std;

std::random_device rd;
std::mt19937 e2(rd());
std::uniform_real_distribution<> dist(0, 1);

Vec3 random_in_unit_sphere() {
    Vec3 p;

    do {
        p = 2.0 * Vec3(dist(e2), dist(e2), dist(e2)) - Vec3(1,1,1);
    } while (p.squared_length() >= 1.0);

    return p;
}

Lambertian::Lambertian(const Vec3 &a): albedo(a) {}

bool Lambertian::scatter(const Ray& r_in, const HitRecord& hr, Vec3& attenuation, Ray& scattered) const {
    Vec3 target = hr.p + hr.normal + random_in_unit_sphere();
    scattered = Ray(hr.p, target - hr.p);
    attenuation = albedo;
    return true;
}
