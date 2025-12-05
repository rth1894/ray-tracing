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
        if (rec.mat_ptr && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
            return attenuation * ray_color(scattered, world, depth - 1);
        }
        return {0,0,0};
    }

    Vec3 unit_direction = normalize(r.direction);
    double t = 0.5 * (unit_direction.y + 1.0);
    return (1.0 - t) * Vec3{1.0, 1.0, 1.0} + t * Vec3{0.5, 0.7, 1.0};
}

int main() {
    // Image
    const double aspect_ratio = 16.0/9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 100;
    const int max_depth = 50;

    // World
    HittableList world;

    auto material_ground = std::make_shared<Lambertian>(Vec3{0.8, 0.8, 0.0});
    auto material_center = std::make_shared<Lambertian>(Vec3{0.7, 0.3, 0.3});
    auto material_left   = std::make_shared<Metal>(Vec3{0.8, 0.8, 0.8}, 0.3);
    auto material_right  = std::make_shared<Metal>(Vec3{0.8, 0.6, 0.2}, 1.0);

    world.add(std::make_shared<Sphere>(Vec3{ 0.0,-100.5,-1.0}, 100.0, material_ground));
    world.add(std::make_shared<Sphere>(Vec3{ 0.0,   0.0,-1.0},   0.5, material_center));
    world.add(std::make_shared<Sphere>(Vec3{-1.0,   0.0,-1.0},   0.5, material_left));
    world.add(std::make_shared<Sphere>(Vec3{ 1.0,   0.0,-1.0},   0.5, material_right));

    // Camera
    Camera cam;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            Vec3 pixel_color{0,0,0};
            for (int s = 0; s < samples_per_pixel; ++s) {
                double u = (i + random_double()) / (image_width - 1);
                double v = (j + random_double()) / (image_height - 1);
                Ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, world, max_depth);
            }
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }
    return 0;
}
