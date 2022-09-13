#ifndef BRAZO_GRUA_H
#define BRAZO_GRUA_H

#include "gancho_grua.h"
#include "cube.h"
#include "object3dr.h"
using namespace _colors_ne;
class _brazogrua : public _object3dr
{
    _cube cubo = _cube();
    _ganchogrua gancho;

public:
    float altura = 5.3;
    float altura_maxima = 5.3;
    float altura_minima = 1.8;

    float posicion = 3.2;
    float posicion_maxima = 3.2;
    float posicion_minima = 0.8;

    void draw(bool point, bool line, bool fill, bool chess);

    void SubirGancho(int n);
    void BajarGancho(int n);

    void SubirAlturaGancho(int n);
    void BajarAlturaGancho(int n);

    void SubirBrazo(int n);
    void BajarBrazo(int n);
};

#endif // BRAZO_GRUA_H
