#include "cilindro.h"

_cilindro::_cilindro(float largo, float anchop, int rotaciones)
{

    alto = largo;
    ancho = anchop;
    rot = rotaciones;

    Vertices.resize(4);
    Vertices[0] = _vertex3f(0, -largo / 2, 0);
    Vertices[1] = _vertex3f(ancho / 2, -largo / 2, 0);
    Vertices[2] = _vertex3f(ancho / 2, largo / 2, 0);
    Vertices[3] = _vertex3f(0, largo / 2, 0);

    revolucion(rotaciones);
}
