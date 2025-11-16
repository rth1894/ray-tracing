#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

class Sphere : public Hittable {
public:
    Vec3 center;
    double radius;

    Sphere(const Vec3& c, double r);
    bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;
};

#endif
