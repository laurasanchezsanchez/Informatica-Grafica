#include "object3dply.h"

_object3dply::_object3dply(string ruta_archivo)
{
    readPly(ruta_archivo);
}

// Saco esta función fuera del constructor para luego poder usarla
void _object3dply::readPly(string ruta_archivo)
{
    archivo.open(ruta_archivo);
    archivo.read(Coordenadas, Posiciones);
    archivo.close();

    Vertices.clear();

    // Por cada vertice hay 3 coordenadas
    int tam = Coordenadas.size() / 3;
    Vertices.resize(tam);

    //genero los vertices
    for (int i = 0; i < tam; ++i)
    {
        Vertices[i] = _vertex3f(
            Coordenadas[3 * i],
            Coordenadas[(3 * i) + 1],
            Coordenadas[(3 * i) + 2]);
    }

    Triangles.resize(1 + (Posiciones.size() / 3) );
    tam = Triangles.size() - 1;

    for (int i = 0; i < tam; ++i)
    {
        Triangles[i] = _vertex3ui((int)Posiciones[i * 3], (int)Posiciones[(i * 3) + 1], (int)Posiciones[(i * 3) + 2]);
    }
}
