#ifndef OBJETO3DREV_H
#define OBJETO3DREV_H

#include "object3d.h"

class _objeto3drev : public _object3D
{
public:
    void revolucion(int rotaciones);
    _vertex3f RotarVY(_vertex3f vert, double angulo);
    _vertex3f RotarVZ(_vertex3f vert, double angulo);
    void definir_caras(int rot, int vperfil);
    void definir_tapas(bool inf, bool sup, int vperfil, int rot);
    double Grados_Radianes(int grados);
};

#endif // OBJETO3DREV_H
