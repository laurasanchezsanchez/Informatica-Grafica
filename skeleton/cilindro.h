#ifndef CILINDRO_H
#define CILINDRO_H

#include "objeto3drev.h"

class _cilindro : public _objeto3drev
{
public:
    float alto;
    float ancho;
    int rot;

    _cilindro(float largo = 1, float anchop = 1, int rotaciones = 6);
};

#endif // CILINDRO_H
