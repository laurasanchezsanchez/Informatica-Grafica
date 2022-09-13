#include "gancho_grua.h"

void _ganchogrua::draw(bool point, bool line, bool fill, bool chess)
{
    //Para el cubo las translaciones en este punto ya están aplicadas
    glPushMatrix();
    glColor3fv((GLfloat *)&BLACK);
    cubo.draw_extendido(point, line, fill, chess);
    glPopMatrix();

    glPushMatrix();
    glColor3fv((GLfloat *)&RED);
    glTranslatef(0, -cubo.tam / 2 - largo / 2, 0);
    glScalef(0.2, largo, 0.2);
    cilindro.draw_extendido(point, line, fill, chess);
    glPopMatrix();
}

void _ganchogrua::SubirAlturaGancho(int parte)
{

    largo = (largo + (largo_maximo - largo_minimo) / parte);
    if (largo > largo_maximo)
        largo = largo_maximo;
}

void _ganchogrua::BajarAlturaGancho(int parte)
{
    largo = (largo - (largo_maximo - largo_minimo) / parte);
    if (largo < largo_minimo)
        largo = largo_minimo;
}
