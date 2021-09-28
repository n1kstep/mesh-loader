#include "MeshLoader.h"


std::vector<Node> MeshLoader::getNodes() {
    return nodes;
}

std::vector<FiniteElement> MeshLoader::getFEs() {
    return allFEs;
}

std::vector<BoundaryFiniteElement> MeshLoader::getBFEs() {
    return allBFEs;
}

std::vector<FiniteElement> MeshLoader::getFEbyId(int n1, int n2, int n3) {
    std::vector<FiniteElement> res;
    std::for_each(allFEs.begin(), allFEs.end(), [&n1, &n2, &n3, &res](FiniteElement fe) {
        if ((std::find(fe.idLst.begin(), fe.idLst.end(), n1) != fe.idLst.end()) &&
            (std::find(fe.idLst.begin(), fe.idLst.end(), n2) != fe.idLst.end()) &&
            (std::find(fe.idLst.begin(), fe.idLst.end(), n3) != fe.idLst.end())) {
            res.push_back(fe);
        }
    });
    return res;
}

std::vector<FiniteElement> MeshLoader::getFEbyEdge(int n1, int n2) {
    std::vector<FiniteElement> res;
    std::for_each(allFEs.begin(), allFEs.end(), [&n1, &n2, &res](FiniteElement fe) {
        if ((std::find(fe.idLst.begin(), fe.idLst.end(), n1) != fe.idLst.end()) &&
            (std::find(fe.idLst.begin(), fe.idLst.end(), n2) != fe.idLst.end())) {
            res.push_back(fe);
        }
    });
    return res;
}

std::vector<Node> MeshLoader::getNodesByBoundaryId(int id) {
    std::set<Node> res;
    auto cur = allBFEs.begin();
    while (cur != allBFEs.end()) {
        cur = std::find_if(cur, allBFEs.end(), [id](const BoundaryFiniteElement &bfe) {
            return bfe.idB == id;
        });
        if (cur != allBFEs.end()) {
            for (const auto &it: cur->idLst) {
                auto nodeById = std::find_if(nodes.begin(), nodes.end(), [it](Node node) {
                    return node.id == it;
                });
                res.insert(*nodeById);
            }
            ++cur;
        }
    }
    return std::vector<Node>(res.begin(), res.end());
}

std::vector<FiniteElement> MeshLoader::getFEsByMaterialId(int id) {
    std::vector<FiniteElement> res;
    std::for_each(allFEs.begin(), allFEs.end(), [&id, &res](const FiniteElement &fe) {
        if (fe.idM == id) {
            res.push_back(fe);
        }
    });
    return res;
}

std::vector<BoundaryFiniteElement> MeshLoader::getBFEsByBoundaryId(int id) {
    std::vector<BoundaryFiniteElement> res;
    std::for_each(allBFEs.begin(), allBFEs.end(), [&id, &res](const BoundaryFiniteElement &bfe) {
        if (bfe.idB == id) {
            res.push_back(bfe);
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

void MeshLoader::insertNode(Node node, FiniteElement &fe, int nId1, int nId2) {
    node.id = nodes.size();
    node.x1 = (nodes[nId1].x1 + nodes[nId2].x1) / 2;
    node.x2 = (nodes[nId1].x2 + nodes[nId2].x2) / 2;
    node.x3 = (nodes[nId1].x3 + nodes[nId2].x3) / 2;

    nodes.push_back(node);
    fe.idLst.push_back(node.id);
    nodes.push_back(node);
}

void MeshLoader::insertNode(Node node, BoundaryFiniteElement &fe, int nId1, int nId2) {
    node.id = nodes.size();
    node.x1 = (nodes[nId1].x1 + nodes[nId2].x1) / 2;
    node.x2 = (nodes[nId1].x2 + nodes[nId2].x2) / 2;
    node.x3 = (nodes[nId1].x3 + nodes[nId2].x3) / 2;

    nodes.push_back(node);
    fe.idLst.push_back(node.id);
    nodes.push_back(node);
}

std::vector<std::vector<Node>> MeshLoader::createContainer() {
    std::vector<std::set<int>> ids(nodes.size() + 1);
    for (auto &it: allFEs) {
        for (auto node1: it.idLst) {
            for (auto node2: it.idLst) {
                ids[node1].insert(node2);
            }
            ids[node1].erase(node1);
        }
    }

    std::vector<std::vector<Node>> res(nodes.size() + 1);
    for (int i = 1; i < nodes.size() + 1; ++i) {
        std::vector<Node> tmp;
        tmp.reserve(ids[i].size());
        for (auto &it_set: ids[i]) {
            tmp.push_back(nodes[it_set]);
        }
        res[i] = std::move(tmp);
    }
    return res;
}