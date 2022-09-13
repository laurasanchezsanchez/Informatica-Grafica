#ifndef GRUA_H
#define GRUA_H

#include "base_grua.h"
#include "brazo_grua.h"
#include "object3dr.h"

// He tenido que poner public para que haga bien el pick
class _grua : public _object3dr
{
  _basegrua base;
  _brazogrua brazo;

public:
  float angulo = 0;

  void draw(bool point, bool line, bool fill, bool chess);

  void GirarDerechaBrazo(int n);
  void GirarIzquierdaBrazo(int n);

  void SubirGancho(int n);
  void BajarGancho(int n);

  void SubirAlturaGancho(int n);
  void BajarAlturaGancho(int n);

  void SubirBrazo(int n);
  void BajarBrazo(int n);
};

#endif // GRUA_H
