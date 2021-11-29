#ifndef CPP_LAB1_ANEUMESHLOADER_H
#define CPP_LAB1_ANEUMESHLOADER_H

#include "MeshLoader.h"
#include "Exceptions.h"
#include <fstream>
#include "iostream"
#include "algorithm"
#include "string"


class AneuMeshLoader : public MeshLoader {
public:
    void loadMesh(const std::string &) override;
};


#endif
