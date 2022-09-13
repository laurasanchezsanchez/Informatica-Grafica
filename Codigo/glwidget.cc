/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */

#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;

/*****************************************************************************/ /**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1) : Window(Window1)
{
    setMinimumSize(300, 300);
    setFocusPolicy(Qt::StrongFocus);
}

/*****************************************************************************/ /**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
    switch (Keyevent->key())
    {

    // PRACTICA 1
    case Qt::Key_1:
        Object = OBJECT_TETRAHEDRON;
        break;
    case Qt::Key_2:
        Object = OBJECT_CUBE;
        break;

    // PRACTICA 2
    case Qt::Key_3:
        Object = OBJECT_CONE;
        break;
    case Qt::Key_4:
        Object = OBJECT_CYLINDER;
        break;
    case Qt::Key_5:
        Object = OBJECT_SPHERE;
        break;
    case Qt::Key_6:
        Object = OBJECT_PLY;
        break;
    case Qt::Key_8:
        Object = OBJECT_PLY_REVOLUTION;
        break;

    // PRACTICA 3
    case Qt::Key_7:
        Object = OBJECT_GRUA;
        break;
    case Qt::Key_A:
    {
        animacionGruaActivada = !animacionGruaActivada;
        if (animacionGruaActivada)
        {
            // Basándome en: connect(timer, &QTimer::timeout, this, &Timer::updateProgress);
            connect(timer, SIGNAL(timeout()), this, SLOT(animacion_grua()));
            timer->start(speedAnimacion);
        }
        else
        {
            disconnect(timer, SIGNAL(timeout()), this, SLOT(animacion_grua()));
            timer->stop();
        }
        break;
    }

    //Primer grado de libertad
    case Qt::Key_Q:
        Grua.SubirAlturaGancho(modificacionAlturaGancho);
        break;
    case Qt::Key_W:
        Grua.BajarAlturaGancho(modificacionAlturaGancho);
        break;

    //Segundo grado de libertad
    case Qt::Key_S:
        Grua.SubirBrazo(modificacionAlturaBrazo);
        break;
    case Qt::Key_D:
        Grua.BajarBrazo(modificacionAlturaBrazo);
        break;

    //Tercer grado de libertad
    case Qt::Key_Z:
        Grua.GirarDerechaBrazo(modificacionGiro);
        break;
    case Qt::Key_X:
        Grua.GirarIzquierdaBrazo(modificacionGiro);
        break;

    //Aumentar o disminuir tasa modificacion 1 grado libertad
    case Qt::Key_E:
    {
        if (modificacionAlturaGancho > 3)
            modificacionAlturaGancho -= 1;
        break;
    }
    case Qt::Key_R:
    {
        if (modificacionAlturaGancho < 27)
            modificacionAlturaGancho += 1;
        break;
    }

    //Modificacion tasa 2 grado libertad
    case Qt::Key_T:
    {
        if (modificacionAlturaBrazo > 3)
            modificacionAlturaBrazo -= 1;
        break;
    }
    case Qt::Key_Y:
    {
        if (modificacionAlturaBrazo < 27)
            modificacionAlturaBrazo += 1;
        break;
    }

    //Modificacion tasa 3 grado libertad
    case Qt::Key_U:
    {
        if (modificacionGiro > 3)
            modificacionGiro -= 1;
        break;
    }
    case Qt::Key_I:
    {
        if (modificacionGiro < 27)
            modificacionGiro += 1;
        break;
    }

    //EXTRA LAURA
    case Qt::Key_G:
        Grua.SubirGancho(modificacionPosicionGancho);
        break;
    case Qt::Key_H:
        Grua.BajarGancho(modificacionPosicionGancho);
        break;


    case Qt::Key_P:
        Draw_point = !Draw_point;
        break;
    case Qt::Key_L:
        Draw_line = !Draw_line;
        break;

    //PRACTICA 4
    case Qt::Key_F:
    {
        Draw_fill = !Draw_fill;
        modoRelleno = !modoRelleno;
        break;
    }
    case Qt::Key_F1:
    {
        if (modoRelleno)
        {
            Draw_chess = dibujoModoFlat = dibujoModoShading = dibujoTextura = false;
            Draw_fill = !Draw_fill;
        }
        break;
    }
    case Qt::Key_F2:
    {
        if (modoRelleno)
        {
            Draw_fill = dibujoModoFlat = dibujoModoShading = dibujoTextura = false;
            Draw_chess = !Draw_chess;
        }
        break;
    }
    case Qt::Key_F3:
    {
        if (modoRelleno)
        {
            Draw_fill = Draw_chess = dibujoModoShading = dibujoTextura = false;
            dibujoModoFlat = !dibujoModoFlat;
        }
        break;
    }
    case Qt::Key_F4:
    {
        if (modoRelleno)
        {
            dibujoModoFlat = Draw_fill = Draw_chess = dibujoTextura = false;
            dibujoModoShading = !dibujoModoShading;
        }
        break;
    }
    case Qt::Key_F5:
    {
        if (modoRelleno)
        {
            dibujoModoShading = dibujoModoFlat = Draw_fill = Draw_chess = false;
            dibujoTextura = !dibujoTextura;
        }
        break;
    }
    case Qt::Key_F6:
    {
        if (modoRelleno)
        {
            dibujoModoShading = Draw_fill = Draw_chess = false;
            dibujoModoFlat = true;
            dibujoTextura = !dibujoTextura;
        }
        break;
    }
    case Qt::Key_F7:
    {
        if (modoRelleno)
        {
            dibujoModoFlat = Draw_fill = Draw_chess = false;
            dibujoModoShading = true;
            dibujoTextura = !dibujoTextura;
        }
        break;
    }

    case Qt::Key_J:
    {
        light0_on = !light0_on;
        break;
    }
    case Qt::Key_K:
    {
        light1_on = !light1_on;
        break;
    }

    case Qt::Key_M:
    {
        material = (material + 1) % nTotalMateriales;
        break;
    }

    case Qt::Key_F11:
    {
        light0_on = !light0_on;
        break;
    }
    case Qt::Key_F12:
    {
        light1_on = !light1_on;
        break;
    }

        //PRACTICA 5
        // C = Perspectiva
    case Qt::Key_C:
    {
        proyeccion_perspectiva = true;
        break;
    }

        // V = Ortogonal / paralela
    case Qt::Key_V:
    {
        proyeccion_perspectiva = false;
        break;
    }

    case Qt::Key_Left:
        Observer_angle_y -= ANGLE_STEP;
        break;
    case Qt::Key_Right:
        Observer_angle_y += ANGLE_STEP;
        break;
    case Qt::Key_Up:
        Observer_angle_x -= ANGLE_STEP;
        break;
    case Qt::Key_Down:
        Observer_angle_x += ANGLE_STEP;
        break;
    case Qt::Key_PageUp:
        Observer_distance *= 1.2;
        break;
    case Qt::Key_PageDown:
        Observer_distance /= 1.2;
        break;
    }

    update();
}

/*****************************************************************************/ /**
 * Evento animacion grua
 *
 *
 *
 *****************************************************************************/

// PRACTICA 3
void _gl_widget::animacion_grua()
{
    if (contadorAnimacion % 50 > 25)
    {
        Grua.GirarDerechaBrazo(modificacionGiro);
        Grua.BajarBrazo(modificacionAlturaBrazo);
        Grua.BajarGancho(modificacionPosicionGancho);
        Grua.BajarAlturaGancho(modificacionAlturaGancho);
    }
    else
    {
        Grua.GirarIzquierdaBrazo(modificacionGiro);
        Grua.SubirBrazo(modificacionAlturaBrazo);
        Grua.SubirGancho(modificacionPosicionGancho);
        Grua.SubirAlturaGancho(modificacionAlturaGancho);
    }
    contadorAnimacion++;
    posicion_luz += 20;
    update();
}

/*****************************************************************************/ /**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/*****************************************************************************/ /**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
    if (proyeccion_perspectiva)
    {
        glFrustum(X_MIN, X_MAX, Y_MIN, Y_MAX, FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);
    }
    else
    {
        glOrtho(X_MINIMO_ORTHO, X_MAXIMO_ORTHO, Y_MINIMO_ORTHO, Y_MAXIMO_ORTHO, FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);
    }
}

/*****************************************************************************/ /**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
    // posicion del observador
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -Observer_distance);
    glRotatef(Observer_angle_x, 1, 0, 0);
    glRotatef(Observer_angle_y, 0, 1, 0);
}

/*****************************************************************************/ /**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
    Axis.draw_line();

    if (Draw_point)
    {
        glPointSize(5);
        glColor3fv((GLfloat *)&BLACK);
        switch (Object)
        {

        // PRACTICA 1
        case OBJECT_TETRAHEDRON:
            Tetrahedron.draw_point();
            break;
        case OBJECT_CUBE:
            Cube.draw_point();
            break;

        // PRACTICA 2
        case OBJECT_CONE:
            Cone.draw_point();
            break;
        case OBJECT_CYLINDER:
            Cylinder.draw_point();
            break;
        case OBJECT_SPHERE:
            Sphere.draw_point();
            break;
        case OBJECT_PLY:
            Ply.draw_point();
            break;
        case OBJECT_PLY_REVOLUTION:
            PlyRevolution.draw_point();
            break;

        case OBJECT_GRUA:
            Grua.draw(1, 0, 0, 0);
            break;
        }
    }

    if (Draw_line)
    {
        glLineWidth(3);
        glColor3fv((GLfloat *)&MAGENTA);
        switch (Object)
        {

        //Practica1
        case OBJECT_TETRAHEDRON:
            Tetrahedron.draw_line();
            break;
        case OBJECT_CUBE:
            Cube.draw_line();
            break;

        //PRACTICA 2
        case OBJECT_CONE:
            Cone.draw_line();
            break;
        case OBJECT_CYLINDER:
            Cylinder.draw_line();
            break;
        case OBJECT_SPHERE:
            Sphere.draw_line();
            break;
        case OBJECT_PLY:
            Ply.draw_line();
            break;
        case OBJECT_PLY_REVOLUTION:
            PlyRevolution.draw_line();
            break;

        case OBJECT_GRUA:
            Grua.draw(0, 1, 0, 0);
            break;
        }
    }

    if (Draw_fill)
    {
        glColor3fv((GLfloat *)&BLUE);
        switch (Object)
        {

        // PRACTICA 1
        case OBJECT_TETRAHEDRON:
            Tetrahedron.draw_fill();
            break;
        case OBJECT_CUBE:
            Cube.draw_fill();
            break;

        // PRACTICA 2
        case OBJECT_CONE:
            Cone.draw_fill();
            break;
        case OBJECT_CYLINDER:
            Cylinder.draw_fill();
            break;
        case OBJECT_SPHERE:
            Sphere.draw_fill();
            break;
        case OBJECT_PLY:
            Ply.draw_fill();
            break;
        case OBJECT_PLY_REVOLUTION:
            PlyRevolution.draw_fill();
            break;

        case OBJECT_GRUA:
            Grua.draw(0, 0, 1, 0);
            break;
        }
    }

    if (Draw_chess)
    {
        switch (Object)
        {
        // PRACTICA 1
        case OBJECT_TETRAHEDRON:
            Tetrahedron.draw_chess();
            break;
        case OBJECT_CUBE:
            Cube.draw_chess();
            break;

        // PRACTICA 2
        case OBJECT_CONE:
            Cone.draw_chess();
            break;
        case OBJECT_CYLINDER:
            Cylinder.draw_chess();
            break;
        case OBJECT_SPHERE:
            Sphere.draw_chess();
            break;
        case OBJECT_PLY:
            Ply.draw_chess();
            break;
        case OBJECT_PLY_REVOLUTION:
            PlyRevolution.draw_chess();
            break;

        case OBJECT_GRUA:
            Grua.draw(0, 0, 0, 1);
            break;
        default:
            break;
        }
    }

    if (dibujoModoFlat || dibujoModoShading)
    {
        if (!lighting)
        {
            glEnable(GL_LIGHTING);
            lighting = true;
        }
        if (!light0_on)
        {
            light0.disable_light(0);
        }
        else
        {
            light0.initialize_light(0);
        }
        if (!light1_on)
        {
            light1.disable_light(1);
        }
        else
        {
            light1.initialize_light(1);
        }

        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materials_ambient[material]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materials_ambient[material]);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materials_ambient[material]);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, materials_shininess[material]);

        glPushMatrix();

        if (posicion_luz != 0)
            glRotatef(posicion_luz, 0, 1, 0);

        //light_position1 representa las coordenadas de donde estará la luz.
        // Como termina en "0.0", indicamos que está en el infinito
        GLfloat light_position1[] = {0, 0, 10, 0.0};
        glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

        glPopMatrix();

        if (dibujoModoFlat)
        {
            switch (Object)
            {
            case OBJECT_TETRAHEDRON:
                Tetrahedron.calcularSombreado('P');
                break;
            case OBJECT_CUBE:
                Cube.calcularSombreado('P');
                break;
            case OBJECT_CYLINDER:
                Cylinder.calcularSombreado('P');
                break;
            case OBJECT_CONE:
                Cone.calcularSombreado('P');
                break;
            case OBJECT_SPHERE:
                Sphere.calcularSombreado('P');
                break;
            case OBJECT_PLY:
                Ply.calcularSombreado('P');
                break;
            case OBJECT_PLY_REVOLUTION:
                PlyRevolution.calcularSombreado('P');
                break;
            default:
                break;
            }
        }

        if (dibujoModoShading)
        {
            switch (Object)
            {
            case OBJECT_TETRAHEDRON:
                Tetrahedron.calcularSombreado('G');
                break;
            case OBJECT_CUBE:
                Cube.calcularSombreado('G');
                break;
            case OBJECT_PLY:
                Ply.calcularSombreado('G');
                break;
            case OBJECT_PLY_REVOLUTION:
                PlyRevolution.calcularSombreado('G');
                break;
            case OBJECT_CYLINDER:
                Cylinder.calcularSombreado('G');
                break;
            case OBJECT_CONE:
                Cone.calcularSombreado('G');
                break;
            case OBJECT_SPHERE:
                Sphere.calcularSombreado('G');
                break;
            default:
                break;
            }
        }
    }
    else
    {
        if (lighting)
        {
            glDisable(GL_LIGHTING);
            lighting = false;
            update();
        }
    }
}

/*****************************************************************************/ /**
 * Evento para inicializar las luces
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initialize_lights()
{
    light0.initialize_ambient(0.4f, 0.4f, 0.4f, 1.0f);
    light0.initialize_diffuse(0.7f, 0.7f, 0.7f, 1.0f);
    light0.initialize_specular(0.2f, 0.2f, 0.2f, 1.0f);
    light0.initialize_position(0.0f, 0.0f, 1.0f, 0.0f);
    light0.initialize_light(0);
    light0_on = true;

    light1.initialize_ambient(0.2f, 0.2f, 0.2f, 1.0f);
    light1.initialize_diffuse(1.0f, 0.0f, 1.0f, 1.0f);
    light1.initialize_specular(1.0f, 0.0f, 1.0f, 1.0f);
    light1.initialize_position(0.0f, 0.0f, 1.0f, 1.0f);
    light1.initialize_light(1);
    light1_on = true;
}

/*****************************************************************************/ /**
 * Evento para inicializar los materiales
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initialize_materials()
{
    // http://www.it.hiof.no/~borres/j3d/explain/light/p-materials.html
    //Chrome
    GLfloat chrome_ambient[4] = {0.25f, 0.25f, 0.25f, 1.0f  };
    GLfloat chrome_diffuse[4] ={0.4f, 0.4f, 0.4f, 1.0f };
    GLfloat chrome_specular[4] ={0.774597f, 0.774597f, 0.774597f, 1.0f };
    GLfloat chrome_shine = 76.8f;

    //Tin
    GLfloat tin_ambient[4] = {0.105882f, 0.058824f, 0.113725f, 1.0f};
    GLfloat tin_diffuse[4] = {0.427451f, 0.470588f, 0.541176f, 1.0f};
    GLfloat tin_specular[4] = {0.333333f, 0.333333f, 0.521569f, 1.0f};
    GLfloat tin_shine = 9.84615f;

    //jade

    GLfloat jade_ambient[4] = {0.135f, 0.2225f, 0.1575f, 0.95f};
    GLfloat jade_diffuse[4] = {0.54f, 0.89f, 0.63f, 0.95f};
    GLfloat jade_specular[4] = {0.316228f, 0.316228f, 0.316228f, 0.95f};
    GLfloat jade_shine = 12.8f;

    for (int i = 0; i < 4; ++i)
    {
        materials_ambient[0][i] = chrome_ambient[i];
        materials_diffuse[0][i] = chrome_diffuse[i];
        materials_specular[0][i] = chrome_specular[i];
    }
    materials_shininess[0] = chrome_shine;
    for (int i = 0; i < 4; ++i)
    {
        materials_ambient[1][i] = tin_ambient[i];
        materials_diffuse[1][i] = tin_diffuse[i];
        materials_specular[1][i] = tin_specular[i];
    }
    materials_shininess[1] = tin_shine;
    for (int i = 0; i < 4; ++i)
    {
        materials_ambient[2][i] = jade_ambient[i];
        materials_diffuse[2][i] = jade_diffuse[i];
        materials_specular[2][i] = jade_specular[i];
    }
    materials_shininess[2] = jade_shine;
}

/*****************************************************************************/ /**
 * Evento para mover la cámara con el ratón pulsando el botón izquierdo
 *
 *
 *
 *****************************************************************************/
void _gl_widget::mouseMoveEvent(QMouseEvent *Event)
{
    if (Event->buttons() & Qt::LeftButton)
    {
        if (mouseY < Event->y())
        {
            Observer_angle_x += ANGLE_STEP;
        }
        else
        {
            if (mouseY > Event->y())
            {
                Observer_angle_x -= ANGLE_STEP;
            }
        }
        if (mouseX < Event->x())
        {
            Observer_angle_y += ANGLE_STEP;
        }
        else
        {
            if (mouseX > Event->x())
            {
                Observer_angle_y -= ANGLE_STEP;
            }
        }

        mouseX = Event->x();
        mouseY = Event->y();
    }
    update();
}

/*****************************************************************************/ /**
 * Evento para obtener la posición seleccionada al pulsar botón derecho del ratón
 *
 *
 *
 *****************************************************************************/

/*
Si hacemos click derecho se colorea en amarillo el triangulo seleccionado
Si hacemos click izquierdo movemos la camara
*/
void _gl_widget::mousePressEvent(QMouseEvent *Event)
{
    if (Event->buttons() & Qt::RightButton)
    {
        posicionXseleccionada = Event->x();
        posicionYseleccionada = height() - Event->y();
    }
}

/*****************************************************************************/ /**
 * Evento para colorear el triángulo seleccionado al pulsar el botón derecho del ratón
 *
 *
 *
 *****************************************************************************/

void _gl_widget::mouseReleaseEvent(QMouseEvent *Event)
{
    if (Draw_fill)
    {
        if (Event->button() & Qt::RightButton)
        {
            pick();
            update();
        }
    }
}

/*****************************************************************************/ /**
 * Evento para hacer zoom
 *
 *
 *
 *****************************************************************************/

// Para el zoom - PRACTICA 5
void _gl_widget::wheelEvent(QWheelEvent *event)
{
    //Delta devuelve la cantidad relativa de rotación de la rueda, en octavos de grado.
    int scroll = event->delta() / 8;
    if (proyeccion_perspectiva)
    {
        if (scroll > 0)
        {
            Observer_distance /= 1.2;
        }
        else
        {
            Observer_distance *= 1.2;
        }
    }
    else
    {
        if (scroll > 0)
        {
            X_MINIMO_ORTHO += 0.1f;
            X_MAXIMO_ORTHO -= 0.1f;
            Y_MINIMO_ORTHO += 0.1f;
            Y_MAXIMO_ORTHO -= 0.1f;
        }
        else
        {
            X_MINIMO_ORTHO -= 0.1f;
            X_MAXIMO_ORTHO += 0.1f;
            Y_MINIMO_ORTHO -= 0.1f;
            Y_MAXIMO_ORTHO += 0.1f;
        }
    }
    update();
}

/*****************************************************************************/ /**
 * Evento para hacer el pick
 *
 *
 *
 *****************************************************************************/

// PRACTICA 5
void _gl_widget::pick()
{
    makeCurrent();

    // Frame Buffer Object to do the off-screen rendering
    GLuint FBO;
    glGenFramebuffers(1, &FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);

    // Texture for drawing
    GLuint Color_texture;
    glGenTextures(1, &Color_texture);
    glBindTexture(GL_TEXTURE_2D, Color_texture);
    // RGBA8
    glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, Window_width, Window_height);
    // this implies that there is not mip mapping
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Texure for computing the depth
    GLuint Depth_texture;
    glGenTextures(1, &Depth_texture);
    glBindTexture(GL_TEXTURE_2D, Depth_texture);
    // Float
    glTexStorage2D(GL_TEXTURE_2D, 1, GL_DEPTH_COMPONENT24, Window_width, Window_height);

    // Attatchment of the textures to the FBO
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, Color_texture, 0);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, Depth_texture, 0);

    // OpenGL will draw to these buffers (only one in this case)
    static const GLenum Draw_buffers[] = {GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, Draw_buffers);

    /*************************/
    // dibujar escena para seleccion
    // - Laura
    clear_window();
    change_projection();
    change_observer();

    switch (Object)
    {
    case OBJECT_TETRAHEDRON:
        Tetrahedron.dibujarTrianguloSeleccionado();
        break;
    case OBJECT_CUBE:
        Cube.dibujarTrianguloSeleccionado();
        break;
    case OBJECT_CONE:
        Cone.dibujarTrianguloSeleccionado();
        break;
    case OBJECT_CYLINDER:
        Cylinder.dibujarTrianguloSeleccionado();
        break;
    case OBJECT_SPHERE:
        Sphere.dibujarTrianguloSeleccionado();
        break;
    case OBJECT_PLY:
        Ply.dibujarTrianguloSeleccionado();
        break;
    case OBJECT_PLY_REVOLUTION:
        PlyRevolution.dibujarTrianguloSeleccionado();
        break;

    default:
        break;
    }

    /*************************/
    // get the pixel
    int Color;
    glReadBuffer(GL_FRONT);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(posicionXseleccionada, posicionYseleccionada, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &Color);
    /*************************/

    // convertir de RGB a identificador
    // - Laura
    unsigned int R = (unsigned int)Color & 0x000000FF;
    unsigned int G = (unsigned int)((Color & 0x0000FF00) >> 8);
    unsigned int B = (unsigned int)((Color & 0x00FF0000) >> 16);

    // actualizar el identificador de la parte seleccionada en el objeto
    // - Laura
    trianguloSeleccionado = (R << 16) + (G << 8) + B;

    switch (Object)
    {
    case OBJECT_TETRAHEDRON:
        Tetrahedron.selected_Triangle(trianguloSeleccionado);
        break;
    case OBJECT_CUBE:
        Cube.selected_Triangle(trianguloSeleccionado);
        break;
    case OBJECT_CONE:
        Cone.selected_Triangle(trianguloSeleccionado);
        break;
    case OBJECT_CYLINDER:
        Cylinder.selected_Triangle(trianguloSeleccionado);
        break;
    case OBJECT_SPHERE:
        Sphere.selected_Triangle(trianguloSeleccionado);
        break;
    case OBJECT_PLY:
        Ply.selected_Triangle(trianguloSeleccionado);
        break;
    case OBJECT_PLY_REVOLUTION:
        PlyRevolution.selected_Triangle(trianguloSeleccionado);
        break;
    default:
        break;
    }
    /*************************/

    glDeleteTextures(1, &Color_texture);
    glDeleteTextures(1, &Depth_texture);
    glDeleteFramebuffers(1, &FBO);
    // the normal framebuffer takes the control of drawing
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, defaultFramebufferObject());
}


/*****************************************************************************/ /**
 * Evento para darle valores a la cámara
 *
 *
 *
 *****************************************************************************/

void _gl_widget::setCamara(GLfloat x, GLfloat y)
{
    Observer_angle_x = x;
    Observer_angle_y = y;
}

/*****************************************************************************/ /**
 * Evento para obtener los valores de la cámara
 *
 *
 *
 *****************************************************************************/
void _gl_widget::getCamara(GLfloat *x, GLfloat *y)
{
    *x = Observer_angle_x;
    *y = Observer_angle_y;
}

/*****************************************************************************/ /**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
    clear_window();
    change_projection();
    change_observer();
    draw_objects();
}

/*****************************************************************************/ /**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
    Window_height = Height1;
    Window_width = Width1;
    glViewport(0, 0, Width1, Height1);
}

/*****************************************************************************/ /**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
    const GLubyte *strm;

    strm = glGetString(GL_VENDOR);
    std::cerr << "Vendor: " << strm << "\n";
    strm = glGetString(GL_RENDERER);
    std::cerr << "Renderer: " << strm << "\n";
    strm = glGetString(GL_VERSION);
    std::cerr << "OpenGL Version: " << strm << "\n";

    if (strm[0] == '1')
    {
        std::cerr << "Only OpenGL 1.X supported!\n";
        exit(-1);
    }

    strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
    std::cerr << "GLSL Version: " << strm << "\n";

    int Max_texture_size = 0;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
    std::cerr << "Max texture size: " << Max_texture_size << "\n";

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    ;

    Observer_angle_x = 0;
    Observer_angle_y = 0;
    Observer_distance = DEFAULT_DISTANCE;

    Draw_point = false;
    Draw_line = true;
    Draw_fill = false;
    Draw_chess = false;

    //PRACTICA 3
    animacionGruaActivada = false;
    speedAnimacion = 100;
    modificacionGiro = 12;
    modificacionAlturaGancho = 12;
    modificacionAlturaBrazo = 12;
    modificacionPosicionGancho = 12;
    contadorAnimacion = 0;

    //PRACTICA 4
    dibujoModoFlat = false;
    dibujoModoShading = false;
    dibujoTextura = false;
    material = 0;
    nTotalMateriales = 3;
    posicion_luz = 0;
    light0_on = false;
    light1_on = false;
    lighting = false;
    modoRelleno = false;

    initialize_lights();
    initialize_materials();

    timer = new QTimer(this);

    //PRACTICA 5
    proyeccion_perspectiva = true;
    mouseX = 0;
    mouseY = 0;
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }

    trianguloSeleccionado = -1;
    Window_width = width();
    Window_height = height();
    //Fin PRACTICA 5
}
