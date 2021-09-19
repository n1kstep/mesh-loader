#include "AneuMeshLoader.h"
#include "Exceptions.h"
#include <fstream>
#include "iostream"
#include "algorithm"


void AneuMeshLoader::loadMesh(const std::string &fileName) {
    std::ifstream inf(fileName);
    if (!inf) {
        throw FileNotFoundException();
    }
    else {
        std::cout << "File " << fileName << " was opened successfully!" << std::endl;
    }

    int amount, dim;
    inf >> amount >> dim;
    nodes.reserve(amount);
    for (int i = 0; i < amount; ++i) {
        Node tmp{};
        inf >> tmp.x1 >> tmp.x2 >> tmp.x3;
        tmp.id = i;
        tmp.vertex = false;
        nodes.push_back(tmp);
    }

    inf >> amount >> dim;
    allFEs.reserve(amount);
    for (int i = 0; i < amount; ++i) {
        FiniteElement tmp{};
        int nodeId;
        inf >> tmp.idM;
        for (int j = 0; j < dim; ++j) {
            inf >> nodeId;
            tmp.idLst.push_back(nodeId);
        }
        tmp.id = i;
        allFEs.push_back(tmp);
    }

    inf >> amount >> dim;
    allBFEs.reserve(amount);
    for (int i = 0; i < amount; ++i) {
        BoundaryFiniteElement tmp{};
        int nodeId;
        inf >> tmp.idB;
        for (int j = 0; j < dim; ++j) {
            inf >> nodeId;
            tmp.idLst.push_back(nodeId);
        }
        tmp.id = i;
        allBFEs.push_back(tmp);
    }
    std::vector<int> allBNodes = getBoundaryNodesId();
    for (auto &it: nodes) {
        if (std::find(allBNodes.begin(), allBNodes.end(), it.id) != allBNodes.end()) {
            it.vertex = true;
        }
    }
    std::cout << "Data was loaded successfully!" << std::endl;
    inf.close();
    std::cout << "File was closed successfully!" << std::endl;
}

std::vector<int> AneuMeshLoader::getBoundaryNodesId() {
    std::vector<int> res;
    for (const auto &it: allBFEs) {
        std::for_each(it.idLst.begin(), it.idLst.end(), [&res](int id) {
            res.push_back(id);
        });
    }
    return res;
}