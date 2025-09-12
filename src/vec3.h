#ifndef VEC3_H
#define VEC3_H
#include <cmath>

struct Vec3 {
    float x = 0, y = 0, z = 0;
};

Vec3 operator+(const Vec3& a, const Vec3& b);
Vec3 operator-(const Vec3& a, const Vec3& b);
Vec3 operator/(const Vec3& a, float scalar);
Vec3 operator*(const Vec3& a, float num);
Vec3 cross(const Vec3& a, const Vec3& b);
float dot(const Vec3& a, const Vec3& b);
float length(const Vec3& a);
Vec3 normalize(const Vec3& a);

#endif
