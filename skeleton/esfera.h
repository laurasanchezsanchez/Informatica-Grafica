#ifndef ESFERA_H
#define ESFERA_H

#include "objeto3drev.h"

class _esfera : public _objeto3drev
{
public:
    _esfera(float radio = 1, float nperfil = 6, int rotaciones = 6);
};

#endif // ESFERA_H
