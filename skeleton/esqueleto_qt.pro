HEADERS += \
  cilindro.h \
  colors.h \
  basic_object3d.h \
  cono.h \
  cubo.h \
  esfera.h \
  object3d.h \
  axis.h \
  objeto3drev.h \
  ply.h \
  tetrahedron.h \
  glwidget.h \
  window.h \
  file_ply_stl.h

SOURCES += \
  basic_object3d.cc \
  cilindro.cpp \
  cono.cpp \
  cubo.cpp \
  esfera.cpp \
  object3d.cc \
  axis.cc \
  objeto3drev.cpp \
  ply.cpp \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc \
  file_ply_stl.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
