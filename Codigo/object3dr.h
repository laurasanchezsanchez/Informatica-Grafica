#ifndef OBJECT3DR_H
#define OBJECT3DR_H

#include "object3d.h"

class _object3dr : public _object3D
{
public:
    void revolucion(int rotaciones);
    _vertex3f RotarEnY(_vertex3f vertice, double angulo);
    _vertex3f RotarEnZ(_vertex3f vertice, double angulo);
    void limitarCaras(int rot, int numVertices);
    void limitarTapas(bool inferior, bool superior, int numVertices, int rot);
};

#endif // OBJ3DR_H
