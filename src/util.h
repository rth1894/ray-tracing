#ifndef UTIL_H
#define UTIL_H

#include "vec3.h"
#include <random>

double random_double(); // [0,1)
double random_double(double min, double max);
Vec3 random_in_unit_sphere();
Vec3 random_unit_vector();
double clamp(double x, double min, double max);
void write_color(std::ostream& out, Vec3 color, int samples_per_pixel);

#endif
