#ifndef CONO_H
#define CONO_H

#include "objeto3drev.h"

class _cono : public _objeto3drev
{
public:
    _cono(float largo = 1, float ancho = 1, int rotaciones = 6);
};

#endif // CONO_H
