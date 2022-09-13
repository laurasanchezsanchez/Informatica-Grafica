HEADERS += \
  base_grua.h \
  brazo_grua.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  file_ply_stl.h \
  gancho_grua.h \
  grua.h \
  light.h \
  object3d.h \
  axis.h \
  object3dply.h \
  object3dr.h \
  object3drevolutionply.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  base_grua.cpp \
  basic_object3d.cc \
  brazo_grua.cpp \
  cone.cpp \
  cube.cpp \
  cylinder.cpp \
  file_ply_stl.cpp \
  gancho_grua.cpp \
  grua.cpp \
  light.cpp \
  object3d.cc \
  axis.cc \
  object3dply.cpp \
  object3dr.cpp \
  object3drevolutionply.cpp \
  sphere.cpp \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc



LIBS += -L/usr/X11R6/lib64 -lGL -lGLEW


CONFIG += c++11
QT += widgets
