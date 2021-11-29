#include "AneuMeshLoader.h"
#include <algorithm>
#include "iostream"


void testMeshLoader(AneuMeshLoader *loader, const std::string &filepath) {
    loader->loadMesh(filepath);
    std::vector<int> nodes;
    std::vector<int> fes;
    std::vector<int> bfes;

    std::cout << "Result of getFEbyId(15, 48, 98) function:\n";
    fes = loader->getFEbyId(15, 48, 98);
    for (int ind: fes) {
        std::cout << ind;
    }
    fes.clear();

    std::cout << "\nResult of getFEbyEdge(15, 48) function:\n";
    fes = loader->getFEbyEdge(15, 48);
    for (int ind: fes) {
        std::cout << ind;
    }
    fes.clear();

    std::cout << "\nResult of getNodesByBoundaryId(1) function:\n";
    nodes = loader->getNodesByBoundaryId(1);
    for (int ind: nodes) {
        std::cout << ind;
    }
    nodes.clear();

    std::cout << "\nResult of getFEsByMaterialId(1) function:\n";
    fes = loader->getFEsByMaterialId(1);
    for (int ind: fes) {
        std::cout << ind;
    }
    fes.clear();

    std::cout << "\nResult of getBFEsByBoundaryId(1) function:\n";
    bfes = loader->getBFEsByBoundaryId(1);
    for (int ind: bfes) {
        std::cout << ind;
    }
    bfes.clear();
}


int main(int argc, char *argv[]) {
    auto *loader = new AneuMeshLoader;
//    std::string path = "/home/nikitast/Documents/CLionProjects/cpp-lab1/cube.mesh";
//    testMeshLoader(loader, path);
    testMeshLoader(loader, argv[0]);
    delete loader;
    return 0;
}