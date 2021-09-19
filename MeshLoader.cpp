#include "MeshLoader.h"
#include "algorithm"
#include "iostream"


std::vector<Node> MeshLoader::getNodes() {
    return nodes;
}

std::vector<FiniteElement> MeshLoader::getFE() {
    return allFEs;
}

std::vector<BoundaryFiniteElement> MeshLoader::getBFE() {
    return allBFEs;
}

FiniteElement MeshLoader::getFEbyId(int n1, int n2, int n3) {
    auto iter = std::find_if(allFEs.begin(), allFEs.end(), [&n1, &n2, &n3](FiniteElement fe) {
        return (std::find(fe.idLst.begin(), fe.idLst.end(), n1) != fe.idLst.end()) &&
               (std::find(fe.idLst.begin(), fe.idLst.end(), n2) != fe.idLst.end()) &&
               (std::find(fe.idLst.begin(), fe.idLst.end(), n3) != fe.idLst.end());
    });
    return *iter;
}

FiniteElement MeshLoader::getFEbyEdge(int n1, int n2) {
    auto iter = std::find_if(allFEs.begin(), allFEs.end(), [&n1, &n2](FiniteElement fe) {
        return (std::find(fe.idLst.begin(), fe.idLst.end(), n1) != fe.idLst.end()) &&
               (std::find(fe.idLst.begin(), fe.idLst.end(), n2) != fe.idLst.end());
    });
    return *iter;
}

std::vector<Node> MeshLoader::getNodesByBoundaryId(int id) {
    std::vector<BoundaryFiniteElement> bfeById;
    std::copy_if(allBFEs.begin(), allBFEs.end(), bfeById.begin(), [&id](const BoundaryFiniteElement &bfe) {
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

std::vector<FiniteElement> MeshLoader::getFEsByMaterialId(int id) {
    std::vector<FiniteElement> res;
    std::copy_if(allFEs.begin(), allFEs.end(), res.begin(), [&id](const FiniteElement &fe) {
        return fe.idM == id;
    });
    return res;
}

std::vector<BoundaryFiniteElement> MeshLoader::getBFEsByBoundaryId(int id) {
    std::vector<BoundaryFiniteElement> res;
    std::copy_if(allBFEs.begin(), allBFEs.end(), res.begin(), [&id](const BoundaryFiniteElement &bfe) {
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

void MeshLoader::insertNode(Node node, FiniteElement& fe, int nId1, int nId2) {
    node.id = nodes.size();
    node.x1 = (nodes[nId1].x1 + nodes[nId2].x1) / 2;
    node.x2 = (nodes[nId1].x2 + nodes[nId2].x2) / 2;
    node.x3 = (nodes[nId1].x3 + nodes[nId2].x3) / 2;

    nodes.push_back(node);
    fe.idLst.push_back(node.id);
    nodes.push_back(node);
}

void MeshLoader::insertNode(Node node, BoundaryFiniteElement& fe, int nId1, int nId2) {
    node.id = nodes.size();
    node.x1 = (nodes[nId1].x1 + nodes[nId2].x1) / 2;
    node.x2 = (nodes[nId1].x2 + nodes[nId2].x2) / 2;
    node.x3 = (nodes[nId1].x3 + nodes[nId2].x3) / 2;

    nodes.push_back(node);
    fe.idLst.push_back(node.id);
    nodes.push_back(node);
}