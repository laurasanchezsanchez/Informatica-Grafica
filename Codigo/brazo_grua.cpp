#include "brazo_grua.h"

void _brazogrua::draw(bool point, bool line, bool fill, bool chess)
{

    float tam_cubo = cubo.tam * 0.5f;

    glPushMatrix();
    // Movemos hacia la derecha y ajustamos
    glTranslatef(1, (tam_cubo / 2), 0);
    glScalef(5, 0.5, 0.5);
    cubo.draw_extendido(point, line, fill, chess);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(posicion, 0, 0);
    gancho.draw(point, line, fill, chess);
    glPopMatrix();
}

void _brazogrua::SubirAlturaGancho(int n)
{
    gancho.SubirAlturaGancho(n);
}
void _brazogrua::BajarAlturaGancho(int n)
{
    gancho.BajarAlturaGancho(n);
}

void _brazogrua::SubirGancho(int n)
{
    posicion = (posicion + (posicion_maxima - posicion_minima) / n);
    if (posicion > posicion_maxima)
        posicion = posicion_maxima;
}

void _brazogrua::BajarGancho(int n)
{
    posicion = (posicion - (posicion_maxima - posicion_minima) / n);
    if (posicion < posicion_minima)
        posicion = posicion_minima;
}

void _brazogrua::SubirBrazo(int n)
{
    altura = (altura + (altura_maxima - altura_minima) / n);
    if (altura > altura_maxima)
        altura = altura_maxima;
}

void _brazogrua::BajarBrazo(int n)
{
    altura = (altura - (altura_maxima - altura_minima) / n);
    if (altura < altura_minima)
        altura = altura_minima;
}
