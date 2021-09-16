#include "AneuMeshLoader.h"
#include <fstream>


void AneuMeshLoader::loadMesh(const std::string& fileName) {
    std::ifstream inf(fileName);
    int amount, dim;
    inf >> amount >> dim;
    for (int i = 0; i < amount; ++i) {
        Node tmp{};
        inf >> tmp.x1 >> tmp.x2 >> tmp.x3;
        tmp.id = i;
        tmp.flag = false;
        nodes.push_back(tmp);
    }
    inf >> amount >> dim;
    for (int i = 0; i < amount; ++i) {
        FiniteElement tmp{};
        int nodeId;
        inf >> tmp.idM;
        for (int j = 0; j < dim; ++j) {
            inf >> nodeId;
            tmp.idLst.push_back(nodeId);
        }
        tmp.id = i;
    }
    inf >> amount >> dim;
    for (int i = 0; i < amount; ++i) {
        BoundaryFiniteElement tmp{};
        int nodeId;
        inf >> tmp.idB;
        for (int j = 0; j < dim; ++j) {
            inf >> nodeId;
            tmp.idLst.push_back(nodeId);
        }
        tmp.id = i;
    }
}
