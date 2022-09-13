#ifndef LIGHT_H
#define LIGHT_H

#include <cmath>
#include <GL/gl.h>

class _light
{
    int id;
    float ang = 0;
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat initial_position[4];
    GLfloat pos[4];

public:
    void initialize_ambient(GLfloat r, GLfloat g, GLfloat b, GLfloat amb);
    void initialize_specular(GLfloat r, GLfloat g, GLfloat b, GLfloat spec);
    void initialize_diffuse(GLfloat r, GLfloat g, GLfloat b, GLfloat dif);
    void initialize_position(GLfloat x, GLfloat y, GLfloat z, GLfloat pos);

    void initialize_light(int id);
    void disable_light(int id);
};

#endif // LIGHT_H
