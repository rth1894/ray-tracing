#ifndef UTIL_H
#define UTIL_H

#include "vec3.h"
#include <cmath>
#include <random>

#pragma once
#include <iostream>
#include "vec3.h"
#include <algorithm>

inline void write_color(std::ostream &out, Vec3 pixel_color, int samples_per_pixel) {
    double r = pixel_color.x;
    double g = pixel_color.y;
    double b = pixel_color.z;

    double scale = 1.0 / samples_per_pixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);

    out << static_cast<int>(256 * std::clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * std::clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * std::clamp(b, 0.0, 0.999)) << '\n';
}

inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

Vec3 random_in_unit_sphere();
Vec3 random_unit_vector();
Vec3 reflect(const Vec3& v, const Vec3& n);
Vec3 refract(const Vec3& uv, const Vec3& n, double etai_over_etat);
bool near_zero(const Vec3& v);
double reflectance(double cosine, double ref_idx);

#endif
