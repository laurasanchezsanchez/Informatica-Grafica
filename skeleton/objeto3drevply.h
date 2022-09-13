#ifndef OBJETO3DREVPLY_H
#define OBJETO3DREVPLY_H

#include "objeto3drev.h"
#include "file_ply_stl.h"

class _objeto3drevply : public _objeto3drev
{
    public:

        _objeto3drevply();
        bool load(string model, int rotaciones = 6);
    private:
        bool leido;
};

#endif // OBJETO3DREVPLY_H
