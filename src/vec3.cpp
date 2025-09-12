#include "vec3.h"

Vec3 operator+(const Vec3& a, const Vec3& b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

Vec3 operator-(const Vec3& a, const Vec3& b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

Vec3 operator*(const Vec3& a, float num) {
    return {a.x * num, a.y * num, a.z * num};
}

Vec3 operator/(const Vec3& a, float scalar) {
    return {a.x / scalar, a.y / scalar, a.z / scalar};
}

Vec3 cross(const Vec3& a, const Vec3& b) {
    return { (a.y*b.z - a.z*b.y), (a.z*b.x - a.x*b.z), (a.x*b.y - a.y*b.x) };
}

float dot(const Vec3& a, const Vec3& b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

float length(const Vec3& a) {
    float squared = (a.x * a.x) + (a.y * a.y) + (a.z * a.z);
    return sqrt(squared);
}

Vec3 normalize(const Vec3& a) {
    float len = length(a);
    if (len == 0) return {0, 0, 0};
    return {a.x / len, a.y / len, a.z / len};
}
