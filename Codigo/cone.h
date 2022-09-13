#ifndef CONO_H
#define CONO_H

#include "object3dr.h"

class _cone : public _object3dr
{
public:
    _cone(float largo = 2.0, float ancho = 1.0, int rotaciones = 10);
    float largo, ancho;
};

#endif // CONO_H
