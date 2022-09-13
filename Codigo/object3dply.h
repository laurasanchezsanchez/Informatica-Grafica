#ifndef OBJECT3DPLY_H
#define OBJECT3DPLY_H

#include "object3d.h"
#include "file_ply_stl.h"

class _object3dply : public _object3D
{
public:
    // Por defecto cogeré la vaca
    _object3dply(string ruta_archivo = "./ply_models/cow.ply");
    void readPly(string ruta_archivo);

private:
    vector<unsigned int> Posiciones;
    vector<float> Coordenadas;
    string ruta_archivo;
    _file_ply archivo;
};

#endif // OBJECT3DPLY_H
