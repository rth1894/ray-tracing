#include "util.h"
#include <algorithm>
#include <cmath>

Vec3 random_in_unit_sphere() {
    while (true) {
        Vec3 p = Vec3{random_double(), random_double(), random_double()}*2.0 - Vec3{1,1,1};
        if (dot(p,p) >= 1) continue;
        return p;
    }
}

Vec3 random_unit_vector() {
    return normalize(random_in_unit_sphere());
}

Vec3 reflect(const Vec3& v, const Vec3& n) {
    return v - 2*dot(v,n)*n;
}

Vec3 refract(const Vec3& uv, const Vec3& n, double etai_over_etat) {
    double cos_theta = fmin(dot(-uv, n), 1.0);
    Vec3 r_out_perp = etai_over_etat * (uv + cos_theta * n);
    Vec3 r_out_parallel = -sqrt(fabs(1.0 - dot(r_out_perp,r_out_perp))) * n;
    return r_out_perp + r_out_parallel;
}

bool near_zero(const Vec3& v) {
    const double s = 1e-8;
    return (fabs(v.x) < s) && (fabs(v.y) < s) && (fabs(v.z) < s);
}

double reflectance(double cosine, double ref_idx) {
    double r0 = (1-ref_idx) / (1+ref_idx);
    r0 = r0 * r0;
    return r0 + (1-r0) * pow(1-cosine,5);
}
