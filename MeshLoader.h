#ifndef CPP_LAB1_MESHLOADER_H
#define CPP_LAB1_MESHLOADER_H

#include "Structures.h"


class MeshLoader {
protected:
    std::vector<Node> nodes;
    std::vector<FiniteElement> feVector;
    std::vector<BoundaryFiniteElement> bfeVector;
public:
    virtual void loadMesh(const std::string &) = 0;

    std::vector<Node> getNodes();

    std::vector<FiniteElement> getFE();

    std::vector<BoundaryFiniteElement> getBFE();

    FiniteElement getFEbyId(int, int, int);

    FiniteElement getFEbyEdge(int, int);

    std::vector<Node> getNodesByBoundaryId(int);

    std::vector<FiniteElement> getFEsByAreaId(int);

    std::vector<BoundaryFiniteElement> getBFEsByBoundaryId(int);

    void insertNode(Node);

    std::vector<std::vector<Node>> createContainer();

    void printNode(const Node &);

    void printFE(const FiniteElement &);

    void printBFE(const BoundaryFiniteElement &);
};

#endif
