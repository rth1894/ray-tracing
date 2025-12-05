#include "material.h"
#include <cmath>

static Vec3 reflect(const Vec3& v, const Vec3& n) {
    return v - 2*dot(v,n)*n;
}

bool Lambertian::scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 scatter_direction = rec.normal + random_unit_vector();
    if (length_squared(scatter_direction) < 1e-8) {
        scatter_direction = rec.normal;
    }
    scattered = Ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}

bool Metal::scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const {
    Vec3 reflected = reflect(normalize(r_in.direction), rec.normal);
    scattered = Ray(rec.p, reflected + fuzz * random_in_unit_sphere());
    attenuation = albedo;
    return (dot(scattered.direction, rec.normal) > 0);
}
