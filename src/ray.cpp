#include "ray.h"
#include <cmath>
#include <algorithm>

Vec3 Ray::at(double t) const {
    return origin + direction * t;
}

Sphere::Sphere(const Vec3& c, double r) : center(c), radius(r) {}

bool Sphere::intersect(const Ray& ray, double& t_hit) const {
    Vec3 L = ray.origin - center;
    double a = dot(ray.direction, ray.direction);
    double b = 2 * dot(ray.direction, L);
    double c = dot(L, L) - radius * radius;

    double delta = b*b - 4*a*c;
    if (delta < 0) return false;

    double sqrt_delta = sqrt(delta);
    double t0 = (-b - sqrt_delta) / (2*a);
    double t1 = (-b + sqrt_delta) / (2*a);

    if (t0 > t1) std::swap(t0, t1);
    if (t0 < 0) {
        t0 = t1;
        if (t0 < 0) return false;
    }

    t_hit = t0;
    return true;
}
