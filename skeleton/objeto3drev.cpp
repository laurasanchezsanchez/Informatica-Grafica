#include "objeto3drev.h"

double _objeto3drev::Grados_Radianes(int grados)
{
    return grados * (M_PI / 180);
}

/*
RotarVY:
- Rotamos sobre el eje Y
*/
_vertex3f _objeto3drev::RotarVY(_vertex3f vert, double angulo)
{

    float z = vert.x * sin(angulo) + vert.z * cos(angulo);
    float x = vert.x * cos(angulo) - vert.z * sin(angulo);
    float y = vert.y;

    vert(x, y, z);
    return vert;
}

/*
RotarVZ:
- Rotamos sobre el eje Z
*/
_vertex3f _objeto3drev::RotarVZ(_vertex3f vert, double angulo)
{

    float z = vert.z;
    float x = vert.x * cos(angulo) - vert.y * sin(angulo);
    float y = vert.x * sin(angulo) + vert.y * cos(angulo);

    vert(x, y, z);
    return vert;
}

void _objeto3drev::definir_caras(int rot, int vperfil)
{

    _vertex3ui triang;
    int tope_cara = rot * vperfil;
    for (int r = 0; r < rot; r++)
    {

        for (int i = 0; i < vperfil - 1; i++)
        {

            triang(i + r * vperfil, i + r * vperfil + 1, (i + (r + 1) * vperfil) % tope_cara);
            Triangles.push_back(triang);
            triang(i + r * vperfil + 1, (i + (r + 1) * vperfil + 1) % tope_cara, (i + (r + 1) * vperfil) % tope_cara);
            Triangles.push_back(triang);
        }
    }
}

void _objeto3drev::definir_tapas(bool inf, bool sup, int vperfil, int rot)
{
    _vertex3ui triang;

    if (inf && sup)
    {
        for (int r = 0; r < rot; r++)
        {
            triang(r * vperfil + vperfil - 1, ((r + 1) * vperfil + vperfil - 1) % (rot * vperfil), Vertices.size() - 2);
            Triangles.push_back(triang);
            triang(r * vperfil, ((r + 1) * vperfil) % (rot * vperfil), Vertices.size() - 1);
            Triangles.push_back(triang);
        }
    }
    if (inf && !sup)
    {
        for (int r = 0; r < rot; r++)
        {
            triang(r * vperfil + vperfil - 1, ((r + 1) * vperfil + vperfil - 1) % (rot * vperfil), Vertices.size() - 1);
            Triangles.push_back(triang);
        }
    }
    if (!inf && sup)
    {
        for (int r = 0; r < rot; r++)
        {
            triang(r * vperfil, ((r + 1) * vperfil) % (rot * vperfil), Vertices.size() - 1);
            Triangles.push_back(triang);
        }
    }
}

/*
Revolucion:
- Calcula el ángulo para rotar
- Si el primer vértice está en x=0 y z=0 (hay tapa superior) lo guardamos a parte y borramos del vector total
- Si el último vértice está en x=0 y z=0 (hay tapa inferior) lo guardamos a parte y borramos del vector total
- Calculamos los vértices ya rotados (sin las tapas)
- Definimos las caras
- Insertamos las tapas si existían
- Definimos las tapas
*/
void _objeto3drev::revolucion(int rotaciones)
{

    _vertex3f tapa_sup;
    _vertex3f tapa_inf;
    double angulo = (2 * M_PI) / rotaciones;
    double inc = angulo;
    bool sup = false;
    bool inf = false;

    vector<_vertex3f>::iterator it;

    it = Vertices.begin();

    if (Vertices[0].x == 0 && Vertices[0].z == 0)
    {
        tapa_sup = Vertices[0];
        Vertices.erase(it);
        sup = true;
    }

    if (Vertices[Vertices.size() - 1].x == 0 && Vertices[Vertices.size() - 1].z == 0)
    {
        tapa_inf = Vertices[Vertices.size() - 1];
        Vertices.pop_back();
        inf = true;
    }

    int vperfil = Vertices.size();
    _vertex3f vert;
    for (int r = 0; r < rotaciones; r++)
    {

        for (int i = 0; i < vperfil; i++)
        {

            vert = Vertices[i];
            Vertices.push_back(RotarVY(vert, angulo));
        }
        angulo += inc;
    }

    definir_caras(rotaciones, vperfil);

    if (inf)
        Vertices.push_back(tapa_inf);
    if (sup)
        Vertices.push_back(tapa_sup);

    definir_tapas(inf, sup, vperfil, rotaciones);
}


