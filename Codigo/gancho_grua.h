#ifndef GANCHO_GRUA_H
#define GANCHO_GRUA_H

#include "object3dr.h"
#include "cube.h"
#include "cylinder.h"
using namespace _colors_ne;

class _ganchogrua : public _object3dr
{
    _cube cubo = _cube();
    _cylinder cilindro = _cylinder();

public:
    float largo = 1.0;
    float largo_minimo = 1.0;
    float largo_maximo = 4.2;

    void draw(bool point, bool line, bool fill, bool chess);
    void SubirAlturaGancho(int parte);
    void BajarAlturaGancho(int parte);
};

#endif // GANCHO_GRUA_H
