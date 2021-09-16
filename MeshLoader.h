#ifndef CPP_LAB1_MESHLOADER_H
#define CPP_LAB1_MESHLOADER_H
#include "Structures.h"


class MeshLoader {
protected:
    std::vector<Node> nodes;
    std::vector<FiniteElement> feVector;
    std::vector<BoundaryFiniteElement> bfeVector;
public:
    virtual void loadMesh() = 0;

    std::vector<Node> getNodes();
    std::vector<FiniteElement> getFE();
    std::vector<BoundaryFiniteElement> getBFE();

    FiniteElement getFEbyId(int, int, int);
    FiniteElement getFEbyEdge(int, int);
    std::vector<Node> getBNodesByBoundaryId(int);
    std::vector<FiniteElement> getFEsByAreaId(int);
    std::vector<BoundaryFiniteElement> getBFEsByBoundaryId(int);
    void insertNode(Node);
    std::vector<std::vector<Node>> createContainer();

    void printNode(int);
    void printFE(int);
    void printBFE(int);
};

#endif
