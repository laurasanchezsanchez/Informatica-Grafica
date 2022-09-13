#include "esfera.h"
#include <cmath>

_esfera::_esfera(float radio, float nperfil, int rotaciones)
{

    Vertices.resize(nperfil);
    Vertices[0] = _vertex3f(0, -radio, 0);

    double angulo = M_PI / (nperfil - 1);

    for (int i = 1; i < nperfil; i++)
    {
        Vertices[i] = RotarVZ(Vertices[0], angulo * i);
    }

    revolucion(rotaciones);
}
