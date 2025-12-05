#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include <memory>

struct HitRecord {
    double t;
    Vec3 p;
    Vec3 normal;
    std::shared_ptr<class Material> mat_ptr; // forward-declare Material
};

class Hittable {
public:
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
    virtual ~Hittable() = default;
};

#endif
