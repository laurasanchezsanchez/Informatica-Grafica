#ifndef CILINDRO_H
#define CILINDRO_H

#include "object3dr.h"

class _cylinder : public _object3dr
{
public:
    float alto;
    float ancho;
    int rot;

    _cylinder(float miAlto = 1.0, float miAncho = 1.0, int rotaciones = 25);
};

#endif // CILINDRO_H
