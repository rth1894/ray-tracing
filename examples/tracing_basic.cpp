// ray equation: P(t) = ray origin + t * ray direction
// where t tells you how far along the ray we are
#include <iostream>
#include "vec3.h"

struct Ray {
    Vec3 origin, direction;
    Vec3 at(double t) const {
        return origin + direction * t;
    }
};

class Sphere {
    public:
        Vec3 center;
        double radius;

    Sphere(const Vec3& c, double r) : center(c), radius(r) {}

        bool intersect(const Ray& ray, double& t_hit) {
            Vec3 L = ray.origin - center;
            double a = dot(ray.direction, ray.direction);
            double b = 2 * dot(ray.direction, L);
            double c = dot (L, L) - radius * radius;

            double delta = b*b - 4*a*c;
            if (delta < 0) return false;
            double sqrt_delta = sqrt(delta);
            double t0 = (-b - sqrt_delta) / (2*a);
            double t1 = (-b + sqrt_delta) / (2*a);
            if (t0 > t1) std::swap(t0, t1);
            if (t0 < 0) {
                t0 = t1;
                if (t0 < 0) return false;
            }
            t_hit = t0;
            return true;
        }
};

int main() {
    // Define a sphere
    Sphere s(Vec3{0, 0, -5}, 1.0);

    // Define a ray (origin at camera, pointing into scene)
    Ray r{Vec3{0, 0, 0}, Vec3{0, 0, -1}};

    double t;
    if (s.intersect(r, t)) {
        std::cout << "Hit sphere at t = " << t << "\n";
        Vec3 hitPoint = r.at(t);
        std::cout << "Hit at (" << hitPoint.x << ", " << hitPoint.y << ", " << hitPoint.z << ")\n";
    } else {
        std::cout << "No hit\n";
    }
}
