#ifndef CPP_LAB1_STRUCTURES_H
#define CPP_LAB1_STRUCTURES_H

#include <vector>
#include "iostream"
#include "iomanip"


class Node {
public:
    int id;
    static constexpr int dim = 3;
    std::array<double, dim> coords{};
    bool vertex;

    Node(int, const std::array<double, dim> &, bool);

    friend std::ostream &operator<<(std::ostream &, const Node &);

    friend std::ostream &operator<<(std::ostream &, const std::vector<Node> &);

    bool operator<(const Node &) const;

    bool operator==(const Node &) const;
};


class FiniteElement {
public:
    int id;
    int idM;
    std::vector<int> idLst;

    friend std::ostream &operator<<(std::ostream &, const FiniteElement &);

    friend std::ostream &operator<<(std::ostream &, const std::vector<FiniteElement> &);
};


class BoundaryFiniteElement {
public:
    int id;
    int idB;
    std::vector<int> idLst;

    friend std::ostream &operator<<(std::ostream &, const BoundaryFiniteElement &);

    friend std::ostream &operator<<(std::ostream &, const std::vector<BoundaryFiniteElement> &);
};


struct Edge {
    std::pair<int, int> edgeNodes;
    int midNode = -1;

    Edge() = default;

    Edge(int, int);

    void updMid(int);

    Edge &operator=(const Edge &);

    bool operator==(const Edge &) const;

    friend std::istream &operator>>(std::istream &, Edge &);

    friend std::ostream &operator<<(std::ostream &, Edge &);
};


#endif
