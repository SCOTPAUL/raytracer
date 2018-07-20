#include "camera.h"

Camera::Camera()
{
    origin = Vec3(0.0,0.0,2.0);
    lower_left = Vec3(-8, -4.5, -1);
    horizontal = Vec3(16.0, 0, 0);
    vertical = Vec3(0, 9.0, 0);
}

Ray Camera::get_ray(double u, double v) {
    return Ray(origin, lower_left + u * horizontal + v * vertical - origin);
}
