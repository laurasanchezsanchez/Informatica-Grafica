/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

/*
Aqui se define el resto de modos a parte de puntos
*/

#include "object3d.h"

using namespace _colors_ne;

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
    glColor3f(0, 0, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < Triangles.size(); i++)
    {
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
    }
    glEnd();
}

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
    glColor3f(0, 1, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < Triangles.size(); i++)
    {
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
    }
    glEnd();
}

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glColor3f(0, 0, 1);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < Triangles.size(); i++)
    {
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
        cambiaColor(i);
    }
    glEnd();
}

//Practica 1 - Funcion propia
void _object3D::cambiaColor(int i)
{
    if (i % 2 == 0)
        glColor3f(1, 0, 0);
    else
        glColor3f(0, 0, 1);
}
