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

    std::vector<int> getBoundaryNodesId();

    std::vector<Node> getNodes();

    std::vector<FiniteElement> getFEs();

    std::vector<BoundaryFiniteElement> getBFEs();

    std::vector<FiniteElement> getFEbyId(int, int, int);

    std::vector<FiniteElement> getFEbyEdge(int, int);

    std::vector<Node> getNodesByBoundaryId(int);

    std::vector<FiniteElement> getFEsByMaterialId(int);

    std::vector<BoundaryFiniteElement> getBFEsByBoundaryId(int);

    void insertNode(Node, FiniteElement &, int, int);

    void insertNode(Node, BoundaryFiniteElement &, int, int);

    std::vector<std::vector<Node>> createContainer();

    static void printNode(const Node &);

    static void printFE(const FiniteElement &);

    static void printBFE(const BoundaryFiniteElement &);
};

#endif
