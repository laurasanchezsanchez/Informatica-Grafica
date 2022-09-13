#ifndef CUBE_H
#define CUBE_H

#include "object3d.h"

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

class _cube : public _object3D
{
public:
  float tam;

  // Por defecto 1x1x1
  _cube(float tamanio = 1.0);
};

#endif
