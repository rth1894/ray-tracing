#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "vec3.h"
#include <memory>

class Material;

struct HitRecord {
    Vec3 p;
    Vec3 normal;
    double t;
    bool front_face;
    std::shared_ptr<class Material> mat_ptr; // forward-declare Material

    inline void set_face_normal(const Ray& r, const Vec3& outward_normal) {
        front_face = dot(r.direction, outward_normal) < 0;

        if (front_face == true)
            normal = outward_normal;
        else
         normal = -outward_normal;
    }
};

class Hittable {
public:
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
    virtual ~Hittable() = default;
};

#endif
