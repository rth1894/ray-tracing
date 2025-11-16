#include "ray.h"

Vec3 Ray::at(double t) const {
    return origin + direction * t;
}
