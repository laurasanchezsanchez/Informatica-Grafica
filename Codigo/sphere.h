#ifndef ESFERA_H
#define ESFERA_H

#include "object3dr.h"

class _sphere : public _object3dr
{
public:
    _sphere(float radio = 1.0, float numVertices = 30, int rotaciones = 25);
};

#endif // ESFERA_H
