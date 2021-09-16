#ifndef CPP_LAB1_STRUCTURES_H
#define CPP_LAB1_STRUCTURES_H
#include <vector>
#include "iostream"
#include "iomanip"


class Node {
public:
    int id;
    double x1, x2, x3;
    bool flag;

    friend std::ostream& operator<<(std::ostream&, const Node&);
};

class FiniteElement {
public:
    int id;
    int idM;
    std::vector<int> idLst;

    friend std::ostream& operator<<(std::ostream&, const FiniteElement&);
};


class BoundaryFiniteElement {
public:
    int id;
    int idB;
    std::vector<int> idLst;

    friend std::ostream& operator<<(std::ostream&, const BoundaryFiniteElement&);
};


#endif
