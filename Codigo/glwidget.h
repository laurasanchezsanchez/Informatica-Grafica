/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/glew.h>

#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
// Practica 1
#include "tetrahedron.h"
#include "cube.h"
// Practica 2
#include "cone.h"
#include "cylinder.h"
#include "sphere.h"
#include "object3dply.h"
#include "object3drevolutionply.h"
// Practica 3
#include "grua.h"
#include <QTimer>

//Practica 4
#include "light.h"

//Practica 5

namespace _gl_widget_ne
{

  const float X_MIN = -.1;
  const float X_MAX = .1;
  const float Y_MIN = -.1;
  const float Y_MAX = .1;
  const float FRONT_PLANE_PERSPECTIVE = (X_MAX - X_MIN) / 2;
  const float BACK_PLANE_PERSPECTIVE = 1000;

  //Practica 5 - la distancia por defecto es 2
  const float DEFAULT_DISTANCE = 2;
  const float ANGLE_STEP = 1;

  typedef enum
  {
    MODE_DRAW_POINT,
    MODE_DRAW_LINE,
    MODE_DRAW_FILL,
    MODE_DRAW_CHESS
  } _mode_draw;
  typedef enum
  {
    OBJECT_TETRAHEDRON,
    OBJECT_CUBE,
    OBJECT_CONE,
    OBJECT_CYLINDER,
    OBJECT_SPHERE,
    OBJECT_PLY,
    OBJECT_PLY_REVOLUTION,
    OBJECT_GRUA
  } _object;
}

class _window;

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
  Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();

  //PRACTICA 4
  void initialize_lights();
  void initialize_materials();

  //Practica 5
  void pick_color(int x, int y);
  void procesar_color(unsigned char color[3]);
  //Practica 5
  void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  void pick();

  //PRACTICA 3
public slots:
  void animacion_grua();

protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;
  void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
  _window *Window;

  _axis Axis;

  //Practica 1
  _tetrahedron Tetrahedron;
  _cube Cube;

  //Practica 2
  _cone Cone;
  _cylinder Cylinder;
  _sphere Sphere;
  _object3dply Ply;
  _object3drevolutionply PlyRevolution;

  //Practica 3
  _grua Grua;
  int speedAnimacion;
  int modificacionGiro;
  int modificacionAlturaGancho;
  int modificacionAlturaBrazo;
  int modificacionPosicionGancho;
  bool animacionGruaActivada;
  int contadorAnimacion;

  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;

  //Practica 4
  bool modoRelleno;
  bool dibujoModoFlat;
  bool dibujoModoShading;

  //Texturas por ahora no van
  bool dibujoTextura;

  bool lighting;
  _light light0;
  _light light1;
  bool light0_on;
  bool light1_on;
  int posicion_luz;
  int material;
  int nTotalMateriales;

  GLfloat materials_ambient[3][4];
  GLfloat materials_diffuse[3][4];
  GLfloat materials_specular[3][4];
  GLfloat materials_shininess[4];

  //Practica 5
  void setCamara(GLfloat x, GLfloat y);
  void getCamara(GLfloat *x, GLfloat *y);

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;

  QTimer *timer;

  //Practica 5
  bool proyeccion_perspectiva;

  float X_MINIMO_ORTHO = -2;
  float Y_MINIMO_ORTHO = -2;
  float X_MAXIMO_ORTHO = 2;
  float Y_MAXIMO_ORTHO = 2;

  //Para el pick
  int Window_width;
  int Window_height;
  int posicionXseleccionada;
  int posicionYseleccionada;
  int trianguloSeleccionado;
  int mouseX;
  int mouseY;
};

#endif
