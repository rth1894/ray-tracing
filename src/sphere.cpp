#include "sphere.h"
#include <cmath>

Sphere::Sphere(const Vec3& c, double r)
    : center(c), radius(r) {}

bool Sphere::hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const {
    Vec3 oc = r.origin - center;
    double a = dot(r.direction, r.direction);
    double b = 2.0 * dot(oc, r.direction);
    double c = dot(oc, oc) - radius * radius;

    double discriminant = b * b - 4.0 * a * c;
    if (discriminant < 0) return false;

    double sqrt_d = std::sqrt(discriminant);

    // Find nearest root
    double t = (-b - sqrt_d) / (2.0 * a);
    if (t < t_min || t > t_max) {
        t = (-b + sqrt_d) / (2.0 * a);
        if (t < t_min || t > t_max) return false;
    }

    rec.t = t;
    rec.p = r.at(t);
    rec.normal = (rec.p - center) / radius;

    return true;
}
