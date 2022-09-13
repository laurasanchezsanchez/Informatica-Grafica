#ifndef BASE_GRUA_H
#define BASE_GRUA_H

#include "object3dr.h"
#include "cylinder.h"
#include "cube.h"
using namespace _colors_ne;

class _basegrua : public _object3dr
{
    // Los creamos con los valores por defecto y luego modificaremos
    _cylinder base1 = _cylinder();
    _cube base2 = _cube();
    _cylinder cilindro = _cylinder();

public:
    void draw(bool point, bool line, bool fill, bool chess);
};

#endif // BASE_GRUA_H
