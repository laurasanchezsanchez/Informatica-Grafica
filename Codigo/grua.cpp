#include "grua.h"
#include "colors.h"

void _grua::draw(bool point, bool line, bool fill, bool chess)
{
    glColor3fv((GLfloat *)&BLACK);
    glPushMatrix();
    base.draw(point, line, fill, chess);
    glPopMatrix();

    glColor3fv((GLfloat *)&MARRON);
    glPushMatrix();
    //Hacemos esta translación para luego no preocuparnos de la altura anterior
    glTranslatef(0, brazo.altura, 0);

    // Directamente la rotación libre, ya que al crearlo ya está el brazo tumbado
    glRotatef(angulo, 0, 1, 0);
    brazo.draw(point, line, fill, chess);
    glPopMatrix();
}

void _grua::GirarDerechaBrazo(int n)
{
    angulo = (angulo + 360 / n);

    // Por si nos pasamos
    if (angulo > 360)
        angulo -= 360;
}

void _grua::GirarIzquierdaBrazo(int n)
{

    angulo = (angulo - 360 / n);
    if (angulo < 0)
        angulo += 360;
}

void _grua::SubirGancho(int n)
{
    brazo.SubirGancho(n);
}
void _grua::SubirAlturaGancho(int n)
{
    brazo.SubirAlturaGancho(n);
}
void _grua::SubirBrazo(int n)
{
    brazo.SubirBrazo(n);
}

void _grua::BajarGancho(int n)
{
    brazo.BajarGancho(n);
}
void _grua::BajarAlturaGancho(int n)
{
    brazo.BajarAlturaGancho(n);
}
void _grua::BajarBrazo(int n)
{
    brazo.BajarBrazo(n);
}
