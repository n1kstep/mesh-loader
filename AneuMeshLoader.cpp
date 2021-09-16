#include "AneuMeshLoader.h"
#include <fstream>
#include "iostream"
#include "algorithm"


void AneuMeshLoader::loadMesh(const std::string &fileName) {
    std::ifstream inf(fileName);
    int amount, dim;
    inf >> amount >> dim;
    for (int i = 0; i < amount; ++i) {
        Node tmp{};
        inf >> tmp.x1 >> tmp.x2 >> tmp.x3;
        tmp.id = i;
        tmp.vertex = false;
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
        feVector.push_back(tmp);
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
        bfeVector.push_back(tmp);
    }
    std::vector<int> allBNodes = getBoundaryNodesId();
    for (auto &it: nodes) {
        if (std::find(allBNodes.begin(), allBNodes.end(), it.id) != allBNodes.end()) {
            it.vertex = true;
        }
    }
}

std::vector<int> AneuMeshLoader::getBoundaryNodesId() {
    std::vector<int> res;
    for (const auto &it: bfeVector) {
        std::for_each(it.idLst.begin(), it.idLst.end(), [&res](int id) {
            res.push_back(id);
        });
    }
    return res;
}