#include "Structures.h"


std::ostream &operator<<(std::ostream &out, const Node &node) {
    out << "Node\t" << node.id;
    out << "\tXYZ\t" << node.x1 << "\t" << node.x2 << "\t" << node.x1;
    out << "\tVertex:\t" << node.vertex;
    out << std::endl;
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
    out << "FE\t" << fe.id;
    out << "\tMaterial Id\t" << fe.idM;
    out << "\tNodes Id:\t";
    for (auto &it: fe.idLst) {
        out << it << "\t";
    }
    out << std::endl;
    return out;
}

std::ostream &operator<<(std::ostream &out, const std::vector<FiniteElement> &fes) {
    for (const auto &it: fes)
        out << it;
    return out;
}

std::ostream &operator<<(std::ostream &out, const BoundaryFiniteElement &bfe) {
    out << "FE\t" << bfe.id;
    out << "\tBoundary Id\t" << bfe.idB;
    out << "\tNodes Id:\t";
    for (auto &it: bfe.idLst) {
        out << it << "\t";
    }
    out << std::endl;
    return out;
}

std::ostream &operator<<(std::ostream &out, const std::vector<BoundaryFiniteElement> &bfes) {
    for (const auto &it: bfes)
        out << it;
    return out;
}