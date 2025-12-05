#ifndef MATERIAL_H
#define MATERIAL_H

#include "ray.h"
#include "util.h"
#include <memory>

struct ScatterRecord {
    Vec3 attenuation;
    Ray scattered;
};

class Material {
public:
    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const = 0;
    virtual ~Material() = default;
};

class Lambertian : public Material {
public:
    Vec3 albedo;
    Lambertian(const Vec3& a) : albedo(a) {}
    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override;
};

class Metal : public Material {
public:
    Vec3 albedo;
    double fuzz;
    Metal(const Vec3& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}
    virtual bool scatter(const Ray& r_in, const HitRecord& rec, Vec3& attenuation, Ray& scattered) const override;
};

#endif
