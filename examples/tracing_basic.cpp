// ray equation: P(t) = ray origin + t * ray direction
// where t tells you how far along the ray we are
#include <iostream>
#include <math.h>

struct Vec3 {
    float x, y, z;
};

Vec3 operator+(const Vec3& a, const Vec3& b) {
    return { (a.x + b.x), (a.y + b.y), (a.z + b.z) };
}
Vec3 operator-(const Vec3& a, const Vec3& b) {
    return { (a.x - b.x), (a.y - b.y), (a.z - b.z) };
}
Vec3 operator*(const Vec3& a, float num) {
    return { (a.x * num), (a.y * num), (a.z * num) };
}
float dot(const Vec3& a, const Vec3& b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
Vec3 cross(const Vec3& a, const Vec3& b) {
    return { (a.y*b.z - a.z*b.y), (a.z*b.x - a.x*b.z), (a.x*b.y - a.y*b.x) };
}

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

    Sphere(Vec3 c, double r) : center(c), radius(r) {}

        bool intersect(Ray& ray, double& t_hit) {
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
    } else {
        std::cout << "No hit\n";
    }
}
