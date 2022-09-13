/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

class _object3D : public _basic_object3D
{
public:
  vector<_vertex3ui> Triangles;

  void draw_line();
  void draw_fill();
  void draw_chess();
  void cambiarColor(int face);
  void draw_extendido(bool point, bool line, bool fill, bool chess);

  //PRACTICA4
  vector<_vertex3f> NormalTriangulos;
  vector<_vertex3f> vectorNormalesVertices;

  //Textura aun no
  vector<_vertex2f> Texture;

  //Calcula el producto vectorial
  void productoVectorial(_vertex3f v1, _vertex3f v2, _vertex3f &normal);
  float producto_escalar(_vertex3f v1, _vertex3f v2);
  void calcularSombreado(char modo);
  void sombreadoGouraud(vector<_vertex3f> suma, vector<double> compartidos);

  //Practica 5
  int selectedTriangle = -1;
  void selected_Triangle(int i);
  void dibujarTrianguloSeleccionado();
};

#endif // OBJECT3D_H
