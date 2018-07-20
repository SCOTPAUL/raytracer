#ifndef SURFACELIST_H
#define SURFACELIST_H

#include "surface.h"


class SurfaceList : public Surface
{
public:
    SurfaceList();
    SurfaceList(Surface **surfaces, int n);
    virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const;
    Surface **list;
    int list_size;
};

#endif // SURFACELIST_H
