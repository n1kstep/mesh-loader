#include "MeshLoader.h"
#include "algorithm"
#include "iostream"


std::vector<Node> MeshLoader::getNodes() {
    return nodes;
}

std::vector<FiniteElement> MeshLoader::getFE() {
    return feVector;
}

std::vector<BoundaryFiniteElement> MeshLoader::getBFE() {
    return bfeVector;
}

FiniteElement MeshLoader::getFEbyId(int n1, int n2, int n3) {
    auto iter = std::find_if(feVector.begin(), feVector.end(), [&n1, &n2, &n3](FiniteElement fe) {
        return (std::find(fe.idLst.begin(), fe.idLst.end(), n1) != fe.idLst.end()) &&
               (std::find(fe.idLst.begin(), fe.idLst.end(), n2) != fe.idLst.end()) &&
               (std::find(fe.idLst.begin(), fe.idLst.end(), n3) != fe.idLst.end());
    });
    return *iter;
}

FiniteElement MeshLoader::getFEbyEdge(int n1, int n2) {
    auto iter = std::find_if(feVector.begin(), feVector.end(), [&n1, &n2](FiniteElement fe) {
        return (std::find(fe.idLst.begin(), fe.idLst.end(), n1) != fe.idLst.end()) &&
               (std::find(fe.idLst.begin(), fe.idLst.end(), n2) != fe.idLst.end());
    });
    return *iter;
}

std::vector<Node> MeshLoader::getNodesByBoundaryId(int id) {
    std::vector<BoundaryFiniteElement> bfeById;
    std::copy_if(bfeVector.begin(), bfeVector.end(), bfeById.begin(), [&id](const BoundaryFiniteElement &bfe) {
        return bfe.idB == id;
    });
    std::vector<Node> res;
    for (const auto &it: bfeById) {
        std::for_each(it.idLst.begin(), it.idLst.end(), [it, this, &res](int id) {
            res.push_back(nodes[id]);
        });
    }
    return res;
}

std::vector<BoundaryFiniteElement> MeshLoader::getBFEsByBoundaryId(int id) {
    std::vector<BoundaryFiniteElement> res;
    std::copy_if(bfeVector.begin(), bfeVector.end(), res.begin(), [&id](const BoundaryFiniteElement &bfe) {
        return bfe.idB == id;
    });
    return res;
}

void MeshLoader::printNode(const Node &node) {
    std::cout << node;
}

void MeshLoader::printFE(const FiniteElement &fe) {
    std::cout << fe;
}

void MeshLoader::printBFE(const BoundaryFiniteElement &bfe) {
    std::cout << bfe;
}
