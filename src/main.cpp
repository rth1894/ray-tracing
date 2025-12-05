#include <iostream>
#include <memory>

#include "vec3.h"
#include "util.h"
#include "ray.h"
#include "camera.h"
#include "hittable_list.h"
#include "sphere.h"
#include "material.h"

Vec3 ray_color(const Ray& r, const Hittable& world, int depth) {
    HitRecord rec;

    if (depth <= 0)
        return {0,0,0};

    if (world.hit(r, 0.001, std::numeric_limits<double>::infinity(), rec)) {
        Ray scattered;
        Vec3 attenuation;
        if (rec.normal.x || rec.normal.y || rec.normal.z) {
            if (rec.normal.x || rec.normal.y || rec.normal.z) {
                // later
            }
        }
    }

    // gradient
    Vec3 unit_direction = normalize(r.direction);
    double t = 0.5 * (unit_direction.y + 1.0);
    return (1.0 - t) * Vec3{1.0, 1.0, 1.0} + t * Vec3{0.5, 0.7, 1.0};
}
