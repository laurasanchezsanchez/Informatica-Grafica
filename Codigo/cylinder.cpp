#include "cylinder.h"

_cylinder::_cylinder(float miLargo, float miAncho, int rotaciones)
{

    alto = miLargo;
    ancho = miAncho;
    rot = rotaciones;

    Vertices.resize(4);
    Vertices[0] = _vertex3f(0, -miLargo / 2, 0);
    Vertices[1] = _vertex3f(miAncho / 2, -miLargo / 2, 0);
    Vertices[2] = _vertex3f(miAncho / 2, miLargo / 2, 0);
    Vertices[3] = _vertex3f(0, miLargo / 2, 0);

    revolucion(rotaciones);
}
