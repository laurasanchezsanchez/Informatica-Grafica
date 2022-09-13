#include "object3drevolutionply.h"

_object3drevolutionply::_object3drevolutionply(string ruta_archivo)
{
    _object3dply aux;

    aux.readPly(ruta_archivo);
    Vertices = aux.Vertices;
    revolucion(20);
}
