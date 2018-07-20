#ifndef VEC3_H
#define VEC3_H


class Vec3
{
public:
    Vec3();
    Vec3(double e0, double e1, double e2);

     double x() const;
     double y() const;
     double z() const;

     double r() const;
     double g() const;
     double b() const;

     const Vec3& operator+() const;
     Vec3 operator-() const;


     double operator[](int i) const;
     double& operator[](int i);

     Vec3& operator+=(const Vec3& v2);
     Vec3& operator-=(const Vec3& v2);
     Vec3& operator*=(const Vec3& v2);
     Vec3& operator/=(const Vec3& v2);
     Vec3& operator*=(const double t);
     Vec3& operator/=(const double t);

     double length() const;
     double squared_length() const;
     Vec3& into_unit_vector();

    double e[3];

};

Vec3 operator+(const Vec3& v1, const Vec3& v2);
Vec3 operator-(const Vec3& v1, const Vec3& v2);
Vec3 operator/(const Vec3& v1, const Vec3& v2);
Vec3 operator*(const Vec3& v1, const Vec3& v2);

Vec3 operator+(double t, const Vec3& v1);
Vec3 operator-(double t, const Vec3& v1);
Vec3 operator*(double t, const Vec3& v1);
Vec3 operator/(double t, const Vec3& v1);

Vec3 operator+(const Vec3& v1, double t);
Vec3 operator-(const Vec3& v1, double t);
Vec3 operator/(const Vec3& v1, double t);
Vec3 operator*(const Vec3& v1, double t);

double dot(const Vec3& v1, const Vec3& v2);
Vec3 cross(const Vec3& v1, const Vec3& v2);

#endif // VEC3_H
