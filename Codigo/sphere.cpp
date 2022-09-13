#include "sphere.h"
#include <cmath>

_sphere::_sphere(float radio, float numVertices, int rotaciones)
{

    Vertices.resize(numVertices);
    Vertices[0] = _vertex3f(0, -radio, 0);
    double angulo = M_PI / (numVertices - 1);

    for (int i = 1; i < numVertices; i++)
    {
        Vertices[i] = RotarEnZ(Vertices[0], angulo * i);
    }

    revolucion(rotaciones);
}
