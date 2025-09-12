#ifndef RAY_H
#define RAY_H

#include "vec3.h"

struct Ray {
    Vec3 origin;
    Vec3 direction;

    Vec3 at(double t) const;
};

class Sphere {
public:
    Vec3 center;
    double radius;

    Sphere(const Vec3& c, double r);

    bool intersect(const Ray& ray, double& t_hit) const;
};

#endif
