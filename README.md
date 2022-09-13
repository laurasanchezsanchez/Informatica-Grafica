# Informática Gráfica - Laura Sánchez Sánchez

### Universidad de Granada. Ingeniería Informática
##### _Prácticas de Informática Gráfica_
---


### Proyecto

###### Resumen del proyecto
La gran ventaja de la infografía, la posibilidad de crear mundos virtuales sin ningún límite, salvo los de las capacidades humanas, implica mucho trabajo, ya que es necesario crear toda una serie de modelos o representaciones de todas las cosas que se pretenden ser tratadas por el ordenador.
Así, es necesario crear modelos de objetos, de la cámara, de la interacción de luz (virtual) con los objetos, del movimiento, etc. A pesar de la dificultad y la complejidad, los resultados obtenidos suelen compensar el esfuerzo.

###### Objetivos que cumple este proyecto:
1. Creación y uso de estructuras de datos que permiten representar objetos 3D simples.
2. Uso de las primitivas de dibujo de OpenGL para dibujar objetos.
3. Cargar modelos guardados en archivos externos en formato PLY (Polygon File Format) y visualizarlos
4. Modelar objetos poligonales sólidos utilizando técnicas sencillas. En este caso, la técnica de modelado se basa en la rotación de un perfil alrededor de un eje, llamado barrido circular.
5. Diseño de modelos jerárquicos de objetos articulados.
6. Controlar los parámetros de animación de los grados de libertad de los modelos jerárquicos utilizando OpenGL.
7. Gestionar y utilizar la pila de transformaciones de OpenGL.
8. Modificar los valores de las transformaciones automáticamente para producir una animación.
9. Respecto a la iluminación:
    - Generar las caras y vértices normales de un modelo poligonal hecho con triángulos
    - Añadir y utilizar fuentes de luz
    - Iluminar un objeto
###### Tecnologías utilizadas
- Qt
- OpenGL


###### Guía de teclas a utilizar:
- Del 1-7 obtendremos diferentes figuras.
- La figura 7 es la diseñada personalmente. Seleccionándola, podemos:
    - Tecla A: Activar/Desactivar la animación.
    - Q/W: Aumentar/disminuir la largura del gancho
    - E/R: aumentamos o disminuimos su tasa de modificacion
    - S/D: Subir/bajar la altura del brazo
    - T/Y: aumentamos o disminuimos su tasa de modificacion
    - Z/X: Girar a la izquierda/derecha el brazo
    - U/I: aumentamos o disminuimos su tasa de modificacion
    - Extra especial: G/H: Subir/bajar el gancho
