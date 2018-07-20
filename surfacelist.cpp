#include "surfacelist.h"

SurfaceList::SurfaceList()
{

}

SurfaceList::SurfaceList(Surface **surfaces, int n){
    list = surfaces;
    list_size = n;
}

bool SurfaceList::hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const {
    HitRecord hr;

    bool hit = false;

    double closest = t_max;

    for(int i = 0; i < list_size; ++i){
        if(list[i]->hit(r, t_min, closest, hr)){
            hit = true;
            closest = hr.t;
            rec = hr;
        }
    }

    return hit;
}
