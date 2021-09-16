#ifndef CPP_LAB1_STRUCTURES_H
#define CPP_LAB1_STRUCTURES_H
#include <vector>


class Node {
public:
    int id;
    double x1, x2, x3;
    bool flag;
};

class FiniteElement {
public:
    int id;
    int idM;
    std::vector<int> idLst;
};

class BoundaryFiniteElement {
public:
    int id;
    int idB;
    std::vector<int> idLst;
};


#endif
