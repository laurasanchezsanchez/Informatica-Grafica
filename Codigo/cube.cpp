#include "cube.h"

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

_cube::_cube(float tamanio)
{
  Vertices.resize(8);

  Vertices[0] = _vertex3f(-tamanio / 2, -tamanio / 2, -tamanio / 2);
  Vertices[1] = _vertex3f(tamanio / 2, -tamanio / 2, -tamanio / 2);
  Vertices[2] = _vertex3f(-tamanio / 2, -tamanio / 2, tamanio / 2);
  Vertices[3] = _vertex3f(tamanio / 2, -tamanio / 2, tamanio / 2);
  Vertices[4] = _vertex3f(-tamanio / 2, tamanio / 2, -tamanio / 2);
  Vertices[5] = _vertex3f(tamanio / 2, tamanio / 2, -tamanio / 2);
  Vertices[6] = _vertex3f(-tamanio / 2, tamanio / 2, tamanio / 2);
  Vertices[7] = _vertex3f(tamanio / 2, tamanio / 2, tamanio / 2);

  Triangles.resize(12);

  Triangles[0] = _vertex3ui(0, 1, 5);
  Triangles[1] = _vertex3ui(5, 4, 0);
  Triangles[2] = _vertex3ui(1, 3, 7);
  Triangles[3] = _vertex3ui(7, 5, 1);
  Triangles[4] = _vertex3ui(3, 2, 6);
  Triangles[5] = _vertex3ui(6, 7, 3);
  Triangles[6] = _vertex3ui(2, 0, 4);
  Triangles[7] = _vertex3ui(4, 6, 2);
  Triangles[8] = _vertex3ui(2, 3, 1);
  Triangles[9] = _vertex3ui(1, 0, 2);
  Triangles[10] = _vertex3ui(7, 6, 4);
  Triangles[11] = _vertex3ui(4, 5, 7);

  // Por si le cambiamos el tamaño por defecto
  tam = tamanio;

}
