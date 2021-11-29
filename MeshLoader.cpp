#include <unordered_set>
#include "MeshLoader.h"
#include "CustomHash.h"


const std::vector<Node> &MeshLoader::getNodes() {
    return nodes;
}

const std::vector<FiniteElement> &MeshLoader::getFEs() {
    return allFEs;
}

const std::vector<BoundaryFiniteElement> &MeshLoader::getBFEs() {
    return allBFEs;
}

std::vector<int> MeshLoader::getFEbyId(int n1, int n2, int n3) {
    std::vector<int> res;
    std::for_each(allFEs.begin(), allFEs.end(), [&n1, &n2, &n3, &res](const FiniteElement &fe) {
        if ((std::find(fe.idLst.begin(), fe.idLst.end(), n1) != fe.idLst.end()) &&
            (std::find(fe.idLst.begin(), fe.idLst.end(), n2) != fe.idLst.end()) &&
            (std::find(fe.idLst.begin(), fe.idLst.end(), n3) != fe.idLst.end())) {
            res.push_back(fe.id);
        }
    });
    return res;
}

std::vector<int> MeshLoader::getFEbyEdge(int n1, int n2) {
    std::vector<int> res;
    std::for_each(allFEs.begin(), allFEs.end(), [&n1, &n2, &res](const FiniteElement &fe) {
        if ((std::find(fe.idLst.begin(), fe.idLst.end(), n1) != fe.idLst.end()) &&
            (std::find(fe.idLst.begin(), fe.idLst.end(), n2) != fe.idLst.end())) {
            res.push_back(fe.id);
        }
    });
    return res;
}

std::vector<int> MeshLoader::getNodesByBoundaryId(int id) {
    std::set<int> res;
    auto cur = allBFEs.begin();
    while (cur != allBFEs.end()) {
        cur = std::find_if(cur, allBFEs.end(), [id](const BoundaryFiniteElement &bfe) {
            return bfe.idB == id;
        });
        if (cur != allBFEs.end()) {
            for (const auto &it: cur->idLst) {
                auto nodeById = std::find_if(nodes.begin(), nodes.end(),
                                             [it](const Node &node) {
                                                 return node.id == it;
                                             });
                res.insert(nodeById->id);
            }
            ++cur;
        }
    }
    return std::vector<int>(res.begin(), res.end());
}

std::vector<int> MeshLoader::getFEsByMaterialId(int id) {
    std::vector<int> res;
    std::for_each(allFEs.begin(), allFEs.end(), [&id, &res](const FiniteElement &fe) {
        if (fe.idM == id) {
            res.push_back(fe.id);
        }
    });
    return res;
}

std::vector<int> MeshLoader::getBFEsByBoundaryId(int id) {
    std::vector<int> res;
    std::for_each(allBFEs.begin(), allBFEs.end(), [&id, &res](const BoundaryFiniteElement &bfe) {
        if (bfe.idB == id) {
            res.push_back(bfe.id);
        }
    });
    return res;
}

void MeshLoader::printNode(const Node &node) {
    std::cout << node;
}

void MeshLoader::printFE(const FiniteElement &fe) {
    std::cout << fe;
}

void MeshLoader::printBFE(const BoundaryFiniteElement &bfe) {
    std::cout << bfe;
}

void MeshLoader::insertNodeMid() {
    std::unordered_set<Edge, hash> edges;
    for (auto &elem: allFEs) {
        std::vector<int> feNodesId = elem.idLst;
        for (int first = 0; first < 4; ++first) {
            for (auto sec = first + 1; sec < 4; ++sec) {
                Edge curEdge(feNodesId[first], feNodesId[sec]);
                if (edges.insert(curEdge).second) {
                    Node newNode = getMidNode(curEdge);
                    curEdge.updMid(newNode.id);
                    nodes.push_back(newNode);
                    elem.idLst.push_back(newNode.id);
                } else {
                    elem.idLst.push_back(curEdge.midNode);
                }
            }
        }
    }
    for (auto &el: allBFEs) {
        std::vector<int> bfeNodesId = el.idLst;
        for (auto first = 0; first < 3; ++first) {
            for (auto sec = first + 1; sec < 3; ++sec) {
                auto curEdgeIter = edges.find({bfeNodesId[first], bfeNodesId[sec]});
                if (curEdgeIter == edges.end()) {
                    curEdgeIter = edges.find({bfeNodesId[sec], bfeNodesId[first]});
                }
                el.idLst.push_back(curEdgeIter->midNode);
            }
        }
    }
}


std::array<double, 3> MeshLoader::getMidEdge(const Edge &edge) {
    double midX = ((nodes.at(edge.edgeNodes.first - 1).coords.at(0)) +
                   (nodes.at(edge.edgeNodes.second - 1).coords.at(0))) / 2;
    double midY = ((nodes.at(edge.edgeNodes.first - 1).coords.at(1)) +
                   (nodes.at(edge.edgeNodes.second - 1).coords.at(1))) / 2;
    double midZ = ((nodes.at(edge.edgeNodes.first - 1).coords.at(2)) +
                   (nodes.at(edge.edgeNodes.second - 1).coords.at(2))) / 2;
    return {midX, midY, midZ};
}

Node MeshLoader::getMidNode(const Edge &edge) {
    Node newNode(nodes.size() + 1, getMidEdge(edge), false);
    return newNode;
}

std::array<double, 3> MeshLoader::getNodeCoords(int id) {
    return nodes.at(id).coords;
}

std::vector<std::set<int>> MeshLoader::createNeighborsVector() {
    std::vector<std::set<int>> neighbors(nodes.size() + 1);
    for (const auto &elem: allBFEs) {
        for (auto nodeId: elem.idLst)
            for (auto anthNodeId: elem.idLst)
                if (nodeId != anthNodeId)
                    neighbors[nodeId].insert(anthNodeId);
    }

    return neighbors;
}

std::vector<int> MeshLoader::getBoundaryNodesId() {
    std::vector<int> res;
    for (const auto &it: allBFEs) {
        std::for_each(it.idLst.begin(), it.idLst.end(), [&res](int id) {
            res.push_back(id);
        });
    }
    return res;
}