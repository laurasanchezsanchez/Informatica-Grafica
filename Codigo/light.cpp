#include "light.h"
#include <iostream>

void _light::initialize_ambient(GLfloat r, GLfloat g, GLfloat b, GLfloat amb)
{
    ambient[0] = r;
    ambient[1] = g;
    ambient[2] = b;
    ambient[3] = amb;
}

void _light::initialize_specular(GLfloat r, GLfloat g, GLfloat b, GLfloat spec)
{
    specular[0] = r;
    specular[1] = g;
    specular[2] = b;
    specular[3] = spec;
}

void _light::initialize_diffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat dif)
{
    diffuse[0] = r;
    diffuse[1] = g;
    diffuse[2] = b;
    diffuse[3] = dif;
}

void _light::initialize_position(GLfloat x, GLfloat y, GLfloat z, GLfloat poss)
{
    initial_position[0] = x;
    initial_position[1] = y;
    initial_position[2] = z;
    initial_position[3] = poss;

    pos[0] = x;
    pos[1] = y;
    pos[2] = z;
    pos[3] = poss;
}

void _light::initialize_light(int id)
{
    switch (id)
    {
    case 0:
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT0, GL_POSITION, pos);
        glEnable(GL_LIGHT0);
        break;
    case 1:
        glLightfv(GL_LIGHT1, GL_SPECULAR, specular);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT1, GL_POSITION, pos);
        glEnable(GL_LIGHT1);
        break;
    }
}
void _light::disable_light(int id)
{
    switch (id)
    {
    case 0:
        glDisable(GL_LIGHT0);
        break;
    case 1:
        glDisable(GL_LIGHT1);
        break;
    }
}
