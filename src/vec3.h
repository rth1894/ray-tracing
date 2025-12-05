#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

struct Vec3 {
    double x = 0;
    double y = 0;
    double z = 0;

    Vec3() = default;
    Vec3(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {}
};

inline Vec3 operator+(const Vec3& a, const Vec3& b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

inline Vec3 operator-(const Vec3& a, const Vec3& b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

inline Vec3 operator-(const Vec3& a) {
    return {-a.x, -a.y, -a.z};
}

inline Vec3 operator*(const Vec3& a, double s) {
    return {a.x * s, a.y * s, a.z * s};
}

inline Vec3 operator*(double s, const Vec3& a) {
    return a * s;
}

inline Vec3 operator*(const Vec3& a, const Vec3& b) {
    return { a.x * b.x, a.y * b.y, a.z * b.z };
}

inline Vec3 operator/(const Vec3& a, double s) {
    return {a.x / s, a.y / s, a.z / s};
}

inline Vec3& operator+=(Vec3& a, const Vec3& b) {
    a.x += b.x; a.y += b.y; a.z += b.z;
    return a;
}

inline double dot(const Vec3& a, const Vec3& b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

inline Vec3 cross(const Vec3& a, const Vec3& b) {
    return { a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x };
}

inline double length(const Vec3& a) {
    return std::sqrt(dot(a,a));
}

inline double length_squared(const Vec3& a) {
    return dot(a,a);
}

inline Vec3 normalize(const Vec3& a) {
    double len = length(a);
    if (len == 0) return {0,0,0};
    return a / len;
}

#endif
