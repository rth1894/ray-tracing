#include "util.h"
#include <limits>
#include <cmath>
#include <iostream>

static std::mt19937_64 rng(std::random_device{}());
static std::uniform_real_distribution<double> uni01(0.0, 1.0);

double random_double() {
    return uni01(rng);
}

double random_double(double min, double max) {
    return min + (max - min) * random_double();
}

Vec3 random_in_unit_sphere() {
    while (true) {
        Vec3 p(random_double(-1,1), random_double(-1,1), random_double(-1,1));
        if (length_squared(p) >= 1) continue;
        return p;
    }
}

Vec3 random_unit_vector() {
    double a = random_double(0, 2*M_PI);
    double z = random_double(-1, 1);
    double r = std::sqrt(1 - z*z);
    return {r*std::cos(a), r*std::sin(a), z};
}

double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}

void write_color(std::ostream& out, Vec3 color, int samples_per_pixel) {
    double r = color.x;
    double g = color.y;
    double b = color.z;

    double scale = 1.0 / samples_per_pixel;
    r = std::sqrt(scale * r);
    g = std::sqrt(scale * g);
    b = std::sqrt(scale * b);

    int ir = static_cast<int>(256 * clamp(r, 0.0, 0.999));
    int ig = static_cast<int>(256 * clamp(g, 0.0, 0.999));
    int ib = static_cast<int>(256 * clamp(b, 0.0, 0.999));

    out << ir << ' ' << ig << ' ' << ib << '\n';
}
