#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.h"
#include "ray.h"

class Camera {
public:
    Vec3 origin;
    Vec3 lower_left_corner;
    Vec3 horizontal;
    Vec3 vertical;

    Camera(double vfov = 90.0, double aspect_ratio = 16.0/9.0) {
        double theta = vfov * M_PI / 180.0;
        double h = tan(theta / 2.0);
        double viewport_height = 2.0 * h;
        double viewport_width = aspect_ratio * viewport_height;

        origin = Vec3{0,0,0};
        horizontal = Vec3{viewport_width,0,0};
        vertical = Vec3{0,viewport_height,0};
        lower_left_corner = origin - horizontal/2 - vertical/2 - Vec3{0,0,1};
    }

    Ray get_ray(double u, double v) const {
        return Ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
    }
};

#endif
