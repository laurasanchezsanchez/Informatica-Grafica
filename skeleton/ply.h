#ifndef PLY_H
#define PLY_H
#include "object3d.h"
#include "file_ply_stl.h"
#include "QString"
class _ply : public _object3D
{
private:
    vector<float> coordinates;
    vector<unsigned int> positions;
    vector<_vertex3f> Vertices_aux;
    vector<_vertex3ui> Triangles_aux;

public:
    _ply();
    _ply(string file_name);
    void create_ply(string &file_name);
    void create_triangles(int tam);
    void conv_triangulos();
    void conv_vertices();
};
#endif // PLY_H
