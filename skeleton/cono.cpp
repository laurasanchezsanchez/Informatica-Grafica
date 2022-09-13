#include "cono.h"

_cono::_cono(float largo, float ancho, int rotaciones)
{

    Vertices.resize(3);
    Vertices[0] = _vertex3f(0, -largo / 2, 0);
    Vertices[1] = _vertex3f(ancho / 2, -largo / 2, 0);
    Vertices[2] = _vertex3f(0, largo / 2, 0);

    revolucion(rotaciones);
}
