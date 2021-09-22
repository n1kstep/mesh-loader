#include "Structures.h"


std::ostream &operator<<(std::ostream &out, const Node &node) {
    std::cout << "Node\t" << node.id;
    std::cout << "\tXYZ\t" << node.x1 << "\t" << node.x2 << "\t" << node.x1;
    std::cout << "\tVertex:\t" << node.vertex;
    std::cout << std::endl;
    return out;
}

std::ostream &operator<<(std::ostream &out, const std::vector<Node> &nodes) {
    for (const auto &it: nodes)
        out << it;
    return out;
}

bool Node::operator<(const Node &node) const {
    return id < node.id;
}

bool Node::operator==(const Node &node) const {
    if (id == node.id && x1 == node.x1 && x2 == node.x2 &&
        x3 == node.x3 && vertex == node.vertex)
        return true;
    else return false;
}

std::ostream &operator<<(std::ostream &out, const FiniteElement &fe) {
    std::cout << "FE\t" << fe.id;
    std::cout << "\tMaterial Id\t" << fe.idM;
    std::cout << "\tNodes Id:\t";
    for (auto &it: fe.idLst) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return out;
}

std::ostream &operator<<(std::ostream &out, const std::vector<FiniteElement> &fes) {
    for (const auto &it: fes)
        out << it;
    return out;
}

std::ostream &operator<<(std::ostream &out, const BoundaryFiniteElement &bfe) {
    std::cout << "FE\t" << bfe.id;
    std::cout << "\tBoundary Id\t" << bfe.idB;
    std::cout << "\tNodes Id:\t";
    for (auto &it: bfe.idLst) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return out;
}

std::ostream &operator<<(std::ostream &out, const std::vector<BoundaryFiniteElement> &bfes) {
    for (const auto &it: bfes)
        out << it;
    return out;
}