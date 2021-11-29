#include "Structures.h"

// NODE

Node::Node(int nId, const std::array<double, 3> &nCoords, bool nVertex)
        : id(nId), coords(nCoords), vertex(nVertex) {}

std::ostream &operator<<(std::ostream &out, const Node &node) {
    out << "Node\t" << node.id;
    out << "\tXYZ\t" << node.coords[0] << "\t" << node.coords[1] << "\t" << node.coords[2];
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
    if (id == node.id && coords[0] == node.coords[0] && coords[1] == node.coords[1] &&
        coords[2] == node.coords[2] && vertex == node.vertex)
        return true;
    else return false;
}

// FINITE ELEMENT

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

// BOUNDARY FINITE ELEMENT

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

// EDGE

Edge::Edge(int firstNodeId, int secNodeId)
        : edgeNodes(std::make_pair(firstNodeId, secNodeId)) {}

void Edge::updMid(int midN) {
    midNode = midN;
}

Edge &Edge::operator=(const Edge &edge) {
    if (this != &edge) {
        this->edgeNodes = edge.edgeNodes;
        this->midNode = edge.midNode;
    }
    return *this;
}

bool Edge::operator==(const Edge &edge) const {
    return (edgeNodes.first == edge.edgeNodes.first) &&
           (edgeNodes.second == edge.edgeNodes.second);
}

std::istream &operator>>(std::istream &in, Edge &edge) {
    in >> edge.edgeNodes.first
       >> edge.edgeNodes.second;
    return in;
}

std::ostream &operator<<(std::ostream &out, Edge &edge) {
    out << edge.edgeNodes.first << ", "
        << edge.edgeNodes.second << std::endl;
    return out;
}
