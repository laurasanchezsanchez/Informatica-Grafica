#include "objeto3drevply.h"

_objeto3drevply::_objeto3drevply(){
}

bool _objeto3drevply::load(string model, int rotaciones){
    _file_ply Ply;
    if(Ply.open("modelos_ply/beethoven.ply")
    {
        Ply.read();
    }
    else
    {
        return false;
    }
    this->Vertices = Ply.Vertices;
    revolucion(rotaciones);
    return true;
}
