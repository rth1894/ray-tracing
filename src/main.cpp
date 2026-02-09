#include <iostream>
#include <memory>

#include "hittable_list.h"
#include "material.h"
#include "ray.h"
#include "sphere.h"
#include "util.h"

#ifdef USE_SFML
#include <SFML/Graphics.hpp>

sf::Color to_sfml_color(const Vec3& c) {
    auto clamp = [](double x) {
        return static_cast<std::uint8_t>(255 * std::clamp(x, 0.0, 1.0));
    };
    return sf::Color(clamp(c.x), clamp(c.y), clamp(c.z));
}
#endif

Vec3 ray_color(const Ray& r, const Hittable& world, int depth) {
    if (depth <= 0) return {0,0,0};

    HitRecord rec;
    if (world.hit(r, 0.001, std::numeric_limits<double>::infinity(), rec)) {
        Ray scattered;
        Vec3 attenuation;
        if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, world, depth-1);
        return {0,0,0};
    }

    Vec3 unit_direction = normalize(r.direction);
    double t = 0.5 * (unit_direction.y + 1.0);
    return (1.0 - t)*Vec3{1,1,1} + t*Vec3{0.5,0.7,1.0};
}

int main() {
    const unsigned image_width  = 400;
    const unsigned image_height = 225;
    const int samples_per_pixel = 20;
    const int max_depth = 5;

    HittableList world;
    auto ground = std::make_shared<Lambertian>(Vec3{0.8,0.8,0.0});
    auto center = std::make_shared<Lambertian>(Vec3{0.1,0.2,0.5});

    world.add(std::make_shared<Sphere>(Vec3{0,-100.5,-1}, 100, ground));
    world.add(std::make_shared<Sphere>(Vec3{0,0,-1}, 0.5, center));

    Vec3 origin{0,0,0};

#ifdef USE_SFML

    // Create window
    sf::RenderWindow window(
        sf::VideoMode(sf::Vector2u(image_width, image_height)),
        "Ray Tracer"
    );

    // Image buffer
    sf::Image img(sf::Vector2u(image_width, image_height), sf::Color::Black);

    // Texture + sprite
    sf::Texture tex(sf::Vector2u(image_width, image_height));
    sf::Sprite sprite(tex);

    // Main render loop
    while (window.isOpen()) {

        // Handle events
        while (auto evOpt = window.pollEvent()) {
            const sf::Event& ev = *evOpt;
            if (ev.is<sf::Event::Closed>())
                window.close();
        }

        // Render image row by row
        for (int y = image_height - 1; y >= 0; --y) {
            for (unsigned x = 0; x < image_width; ++x) {
                Vec3 col{0,0,0};

                for (int s = 0; s < samples_per_pixel; ++s) {
                    double u = (x + random_double()) / (image_width - 1);
                    double v = (y + random_double()) / (image_height - 1);
                    Ray r(origin, Vec3{u - 0.5, v - 0.5, -1});
                    col = col + ray_color(r, world, max_depth);
                }

                col = col / double(samples_per_pixel);
                img.setPixel(sf::Vector2u{x, image_height - 1 - y}, to_sfml_color(col));
            }

            // Update texture and display
            tex.update(img.getPixelsPtr());
            window.clear();
            window.draw(sprite);
            window.display();
        }
    }

#else
    // PPM output for non-SFML
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";
    for (int j = image_height - 1; j >= 0; --j) {
        for (unsigned i = 0; i < image_width; ++i) {
            Vec3 pixel_color{0,0,0};
            for (int s = 0; s < samples_per_pixel; ++s) {
                double u = (i + random_double()) / (image_width - 1);
                double v = (j + random_double()) / (image_height - 1);
                Ray r(origin, Vec3{u - 0.5, v - 0.5, -1});
                pixel_color = pixel_color + ray_color(r, world, max_depth);
            }
            pixel_color = pixel_color / double(samples_per_pixel);
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }
#endif

    return 0;
}
