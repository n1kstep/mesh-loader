#ifndef CPP_LAB1_ANEUMESHLOADER_H
#define CPP_LAB1_ANEUMESHLOADER_H
#include "MeshLoader.h"
#include "string"


class AneuMeshLoader : MeshLoader {
    void loadMesh(const std::string& fileName);
};


#endif
