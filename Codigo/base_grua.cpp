#include "base_grua.h"

void _basegrua::draw(bool point, bool line, bool fill, bool chess)
{
    float escalaAltoBase1 = 0.5f;
    float escalaAltoBase2 = 0.3f;
    float alto_base = cilindro.alto * escalaAltoBase1;
    float alto_cubo = base2.tam * escalaAltoBase2;
    float alto_cilindro = base1.alto * 5;

    //Primero se escala y luego se translada
    glPushMatrix();
    glTranslatef(0, alto_base / 2, 0);
    glScalef(2, escalaAltoBase1, 2);
    base1.draw_extendido(point, line, fill, chess);
    glPopMatrix();

    glColor3fv((GLfloat *)&MARRON);
    glPushMatrix();
    glTranslatef(0, alto_base + alto_cubo / 2, 0);
    glScalef(1, escalaAltoBase2, 1);
    base2.draw_extendido(point, line, fill, chess);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, alto_base + alto_cubo + alto_cilindro / 2, 0);
    glScalef(0.5f, 5, 0.5f);
    cilindro.draw_extendido(point, line, fill, chess);
    glPopMatrix();
}
