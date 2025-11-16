#ifndef VEC3_H
#define VEC3_H
#include <cmath>

struct Vec3 {
    double x = 0, y = 0, z = 0;
};

Vec3 operator+(const Vec3& a, const Vec3& b);
Vec3 operator-(const Vec3& a, const Vec3& b);
Vec3 operator/(const Vec3& a, double scalar);
Vec3 operator*(const Vec3& a, double num);
Vec3 operator*(double num, const Vec3& a);
Vec3 cross(const Vec3& a, const Vec3& b);
double dot(const Vec3& a, const Vec3& b);
double length(const Vec3& a);
Vec3 normalize(const Vec3& a);

#endif
