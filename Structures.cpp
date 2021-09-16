#include "Structures.h"


std::ostream& operator<<(std::ostream& out, const Node& node) {
    std::cout << "Node\t" << node.id;
    std::cout << "XYZ\t" << node.x1 << node.x2 << node.x1;
    std::cout << "Vertex:\t" << node.flag;
    return out;
}

std::ostream &operator<<(std::ostream& out, const FiniteElement& fe) {
    std::cout << "FE\t" << fe.id;
    std::cout << "Material Id\t" << fe.idM;
    std::cout << "Nodes Id:\n";
    for (auto & it : fe.idLst) {
        std::cout << it;
    }
    return out;
}

std::ostream &operator<<(std::ostream& out, const BoundaryFiniteElement& bfe) {
    std::cout << "FE\t" << bfe.id;
    std::cout << "Boundary Id\t" << bfe.idB;
    std::cout << "Nodes Id:\n";
    for (auto & it : bfe.idLst) {
        std::cout << it;
    }
    return out;
}