#include <iostream>
#include "ray.h"
#include "sphere.h"

Vec3 ray_color(const Ray& r, const Hittable& world) {
    HitRecord rec;
    if (world.hit(r, 0.001f, 1000.0f, rec)) {
        Vec3 N = normalize(rec.normal);
        return {0.5 * (N.x + 1.0), 0.5 * (N.y + 1.0), 0.5 * (N.z + 1.0)};
    }

    // bg gradient
    Vec3 unit_dir = normalize(r.direction);
    double t = 0.5 * (unit_dir.y + 1.0);
    return (1.0 - t) * Vec3{1.0, 1.0, 1.0} + t * Vec3{0.5, 0.7, 1.0};
}

int main() {
    const int image_width = 400;
    const int image_height = 200;

    // camera
    Vec3 origin = {0, 0, 0};
    Vec3 lower_left_corner = {-2.0, -1.0, -1.0};
    Vec3 horizontal = {4.0, 0.0, 0.0};
    Vec3 vertical = {0.0, 2.0, 0.0};

    // world
    Sphere world({0, 0, -3}, 0.5);

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            double u = double(i) / (image_width - 1);
            double v = double(j) / (image_height - 1);

            Vec3 direction = lower_left_corner + horizontal * u + vertical * v - origin;
            Ray r(origin, direction);

            Vec3 col = ray_color(r, world);

            int ir = static_cast<int>(255.999 * col.x);
            int ig = static_cast<int>(255.999 * col.y);
            int ib = static_cast<int>(255.999 * col.z);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    return 0;
}
