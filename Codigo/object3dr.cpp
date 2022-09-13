#include "object3dr.h"


_vertex3f _object3dr::RotarEnY(_vertex3f vertice, double angulo)
{
    // Formulas
    float x = vertice.x * cos(angulo) - vertice.z * sin(angulo);
    float y = vertice.y;
    float z = vertice.x * sin(angulo) + vertice.z * cos(angulo);
    vertice(x, y, z);

    return vertice;
}

_vertex3f _object3dr::RotarEnZ(_vertex3f vertice, double angulo)
{
    float x = vertice.x * cos(angulo) - vertice.y * sin(angulo);
    float y = vertice.x * sin(angulo) + vertice.y * cos(angulo);
    float z = vertice.z;
    vertice(x, y, z);

    return vertice;
}

void _object3dr::limitarCaras(int rot, int numVertices)
{
    _vertex3ui triangulo;
    int tope_cara = rot * numVertices;

    for (int r = 0; r < rot; r++)
    {
        for (int i = 0; i < numVertices - 1; i++)
        {
            triangulo(i + r * numVertices, i + r * numVertices + 1, (i + (r + 1) * numVertices) % tope_cara);
            Triangles.push_back(triangulo);
            triangulo(i + r * numVertices + 1, (i + (r + 1) * numVertices + 1) % tope_cara, (i + (r + 1) * numVertices) % tope_cara);
            Triangles.push_back(triangulo);
        }
    }
}

void _object3dr::limitarTapas(bool inferior, bool superior, int numVertices, int rot)
{
    _vertex3ui triang;

    // Según lo que haya:
    if (inferior && superior)
    {
        for (int r = 0; r < rot; r++)
        {
            triang(r * numVertices + numVertices - 1, ((r + 1) * numVertices + numVertices - 1) % (rot * numVertices), Vertices.size() - 2);
            Triangles.push_back(triang);
            triang(r * numVertices, ((r + 1) * numVertices) % (rot * numVertices), Vertices.size() - 1);
            Triangles.push_back(triang);
        }
    }
    if (inferior && !superior)
    {
        for (int r = 0; r < rot; r++)
        {
            triang(r * numVertices + numVertices - 1, ((r + 1) * numVertices + numVertices - 1) % (rot * numVertices), Vertices.size() - 1);
            Triangles.push_back(triang);
        }
    }
    if (!inferior && superior)
    {
        for (int r = 0; r < rot; r++)
        {
            triang(r * numVertices, ((r + 1) * numVertices) % (rot * numVertices), Vertices.size() - 1);
            Triangles.push_back(triang);
        }
    }
}

void _object3dr::revolucion(int rotaciones)
{
    _vertex3f tapa_superior;
    _vertex3f tapa_inferior;
    double angulo = (2 * M_PI) / rotaciones;

    // Para luego ir sumando al ángulo
    double incrementoAngulo = angulo;
    bool superior = false;
    bool inferior = false;

    vector<_vertex3f>::iterator it;
    it = Vertices.begin();

    if (Vertices[0].x == 0 && Vertices[0].z == 0)
    {
        tapa_superior = Vertices[0];
        Vertices.erase(it);
        superior = true;
    }

    if (Vertices[Vertices.size() - 1].x == 0 && Vertices[Vertices.size() - 1].z == 0)
    {
        tapa_inferior = Vertices[Vertices.size() - 1];
        Vertices.pop_back();
        inferior = true;
    }

    int numVertices = Vertices.size();
    _vertex3f vertice;

    for (int r = 0; r < rotaciones; r++)
    {
        for (int i = 0; i < numVertices; i++)
        {
            vertice = Vertices[i];
            Vertices.push_back(RotarEnY(vertice, angulo));
        }
        angulo += incrementoAngulo;
    }

    limitarCaras(rotaciones, numVertices);

    if (inferior)
        Vertices.push_back(tapa_inferior);
    if (superior)
        Vertices.push_back(tapa_superior);

    limitarTapas(inferior, superior, numVertices, rotaciones);
}
