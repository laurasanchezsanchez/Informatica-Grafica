/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
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
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // GL_TRIANGLES: Trata cada triplete de vértices como un triángulo independiente.
    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < Triangles.size(); i++)
    {
        //glVertex3fv: Especifica un vértice
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

//Nuevo - practica 5
void _object3D::draw_fill()
{
    glColor3f(0, 0, 1);

    //Cambiamos la 2 instrucción para que se dibuje el interior
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < Triangles.size(); i++)
    {
        if (i == selectedTriangle)
        {
            glColor3fv((GLfloat *)&YEllOW);
        }
        else
        {
            glColor3fv((GLfloat *)&BLUE);
        }
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
    }
    glEnd();
}

void _object3D::selected_Triangle(int Triangle)
{
    selectedTriangle = Triangle;
}

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
        cambiarColor(i);
    }
    glEnd();
}

void _object3D::draw_extendido(bool point, bool line, bool fill, bool chess)
{
    if (point)
    {
        draw_point();
    }
    if (line)
    {
        draw_line();
    }
    if (fill)
    {
        draw_fill();
    }
    if (chess)
    {
        draw_chess();
    }
}

void _object3D::cambiarColor(int face) // Función encargada de alternar colores (azul y rojo en este caso)
{
    if (face % 2 == 0)
        glColor3f(1, 0, 0);
    else
        glColor3f(0, 0, 1);
}


//PRACTICA 4
//Producto vectorial
void _object3D::productoVectorial(_vertex3f vertice1, _vertex3f vertice2, _vertex3f &vector_producto)
{
    int k = 1;
    _vertex3f partePositiva;
    _vertex3f parteNegativa;

    for (int i = 0; i < 3; i++)
    {
        partePositiva[i] = (vertice1[k % 3] * vertice2[(k + 1) % 3]);
        k++;
    }

    k = 2;
    //Parte negativa
    for (int i = 0; i < 3; i++)
    {
        parteNegativa[i] = (vertice1[k % 3] * vertice2[(k - 1) % 3]);
        k++;
    }

    for (int i = 0; i < 3; i++)
    {
        vector_producto[i] = partePositiva[i] - parteNegativa[i];
    }
}

// NUEVO
float _object3D::producto_escalar(_vertex3f vertice1, _vertex3f vertice2)
{
    return vertice1.x*vertice2.x + vertice1.y*vertice2.y + vertice1.z*vertice2.z;
}

void _object3D::calcularSombreado(char modo)
{
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_TRIANGLES);

    vector<_vertex3f> SumaNormalesTriangulos;
    vector<double> verticesCompartidos;
    SumaNormalesTriangulos.resize(Vertices.size());
    verticesCompartidos.resize(Vertices.size());

    // Calcular la normal
    for (unsigned int i = 0; i < Triangles.size(); i++)
    {
        _vertex3f vertice1 = Vertices[Triangles[i]._0];
        _vertex3f vertice2 = Vertices[Triangles[i]._1];
        _vertex3f vertice3 = Vertices[Triangles[i]._2];

        _vertex3f vector1;
        _vertex3f vector2;

        vector1._0 = (vertice2._0 - vertice1._0);
        vector1._1 = (vertice2._1 - vertice1._1);
        vector1._2 = (vertice2._2 - vertice1._2);

        vector2._0 = (vertice3._0 - vertice1._0);
        vector2._1 = (vertice3._1 - vertice1._1);
        vector2._2 = (vertice3._2 - vertice1._2);
        
        _vertex3f normal;
        productoVectorial(vector1, vector2, normal);

        /*
        if (producto_escalar(normal, vertice1) < 0.0)
        {
            normal.x = -normal.x;
            normal.y = -normal.y;
            normal.z = -normal.z;
        }
        */

        NormalTriangulos.push_back(normal.normalize());

        // Modo plano (P)
        if (modo == 'P')
        {
            glNormal3f(NormalTriangulos[i].x, NormalTriangulos[i].y, NormalTriangulos[i].z);
            glVertex3fv((GLfloat *) &vertice1);
            glVertex3fv((GLfloat *) &vertice2);
            glVertex3fv((GLfloat *) &vertice3);
        }
    }

    // Fin iluminacion plana

    // Fuera del for anterior
   if (modo == 'G') // Gouraud
   {
        sombreadoGouraud(SumaNormalesTriangulos, verticesCompartidos);
    }
    glEnd();
    // FIN ILUMINACION Gouraud
}

void _object3D::sombreadoGouraud(vector<_vertex3f> SumaNormalesTriangulos, vector<double> verticesCompartidos)
{
    // Sacamos la suma de normales y contador para hacer la media
    for (unsigned int i = 0; i < Triangles.size(); i++)
    {
        // Sumamos todas las normales de los triangulos que comparten ese vertice
        SumaNormalesTriangulos[Triangles[i]._0] += NormalTriangulos[i];
        //¿Cuantos triangulos pasan por ese vertice?
        verticesCompartidos[Triangles[i]._0]++;

        SumaNormalesTriangulos[Triangles[i]._1] += NormalTriangulos[i];
        verticesCompartidos[Triangles[i]._1]++;

        SumaNormalesTriangulos[Triangles[i]._2] += NormalTriangulos[i];
        verticesCompartidos[Triangles[i]._2]++;
    }

    // Hacemos la media
    for (unsigned int i = 0; i < SumaNormalesTriangulos.size(); i++)
    {
        _vertex3f normalVertice(SumaNormalesTriangulos[i].x / verticesCompartidos[i], SumaNormalesTriangulos[i].y / verticesCompartidos[i], SumaNormalesTriangulos[i].z / verticesCompartidos[i]);
        vectorNormalesVertices.push_back(normalVertice.normalize());
    }

    // Formato
    for (unsigned int i = 0; i < Triangles.size(); i++)
    {
        glNormal3fv((GLfloat *) &vectorNormalesVertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

        glNormal3fv((GLfloat *) &vectorNormalesVertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

        glNormal3fv((GLfloat *) &vectorNormalesVertices[Triangles[i]._2]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
}

void _object3D::dibujarTrianguloSeleccionado()
{
    _vertex3f id;
    _vertex4f color;

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < Triangles.size(); i++)
    {
        // Ayuda de internet + apuntes
        id.r = (float)((i & 0x00FF0000) >> 16);
        id.g = (float)((i & 0x0000FF00) >> 8);
        id.b = (float)(i & 0x000000FF);
        id = id / 255.0f;

        color = _vertex4f(id.r, id.g, id.b, 1);

        glColor3fv((GLfloat *)&color);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *)&Vertices[Triangles[i]._2]);
    }
    glEnd();
}
