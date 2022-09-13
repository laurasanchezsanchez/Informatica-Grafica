#include "ply.h"
_ply::_ply() {}
_ply::_ply(string file_name)
{
    _file_ply archivo;
    //abre el archivo si puede acceder
    if (archivo.open(file_name))
    {
        //lee el contenido y lo guarda en las variables coordinates and positions
        archivo.read(coordinates, positions);
        //cierro el flujo
        archivo.close();
        //limpio el vector de vertices
        Vertices.clear();
        //porque son 3 coordenadas (x,y,z) y tiene que recorrer de 3 en 3
        Vertices.resize(coordinates.size() / 3);
        //guardo el tamaño
        int tam = Vertices.size();
        //genero los vertices
        for (int i = 0; i < tam; ++i)
        {
            //va de 3 en 3 porque son 3 coordenadas
            //ej: 1,2,3,4,5,6 (hay 2 coordenadas)
            //(1,2,3) y (4,5,6) (x,y,z)
            Vertices[i] = _vertex3f(
                coordinates[i * 3],
                coordinates[(3 * i) + 1],
                coordinates[(3 * i) + 2]);
        }
        //aqui lo mismo lo dividimos entre 3
        //porque tiene que seleccionar 3 puntos
        //para formar el triangulo
        Triangles.resize((positions.size() / 3) + 1);
        tam = Triangles.size() - 1;
        //genero los triangulos
        for (int i = 0; i < tam; ++i)
        {
            Triangles[i] = _vertex3ui((int)positions[i * 3], (int)positions[(i * 3) + 1], (int)positions[(i * 3) + 2]);
        }
    }
    else
    {
        cout << "Error Archivo no leido" << endl;
    }
}
