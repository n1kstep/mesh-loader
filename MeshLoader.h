#ifndef CPP_LAB1_MESHLOADER_H
#define CPP_LAB1_MESHLOADER_H

#include "Structures.h"
#include "Exceptions.h"
#include "algorithm"
#include "iostream"
#include "fstream"
#include "set"


class MeshLoader {
protected:
    std::vector<Node> nodes;
    std::vector<FiniteElement> allFEs;
    std::vector<BoundaryFiniteElement> allBFEs;
public:
    virtual void loadMesh(const std::string &) = 0;

    virtual ~MeshLoader() = default;

    const std::vector<Node> &getNodes();

    const std::vector<FiniteElement> &getFEs();

    const std::vector<BoundaryFiniteElement> &getBFEs();

    std::vector<int> getFEbyId(int, int, int);

    std::vector<int> getFEbyEdge(int, int);

    std::vector<int> getNodesByBoundaryId(int);

    std::vector<int> getFEsByMaterialId(int);

    std::vector<int> getBFEsByBoundaryId(int);

    void insertNodeMid();

    std::vector<std::set<int>> createNeighborsVector();

    static void printNode(const Node &);

    static void printFE(const FiniteElement &);

    static void printBFE(const BoundaryFiniteElement &);

    std::vector<int> getBoundaryNodesId();

private:
    Node getMidNode(const Edge &);

    std::array<double, Node::dim> getMidEdge(const Edge &);

    std::array<double, Node::dim> getNodeCoords(int);

};

#endif
