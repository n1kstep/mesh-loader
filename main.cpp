#include "AneuMeshLoader.h"
#include <algorithm>


void testMeshLoader(AneuMeshLoader *loader, const std::string &filepath_) {
    loader->loadMesh(filepath_);
    std::vector<Node> nodes;
    std::vector<FiniteElement> fes;
    std::vector<BoundaryFiniteElement> bfes;

    std::cout << "Result of getFEbyId(15, 48, 98) function:\n";
    fes = loader->getFEbyId(15, 48, 98);
    std::cout << fes;
    fes.clear();

    std::cout << "\nResult of getFEbyEdge(15, 48) function:\n";
    fes = loader->getFEbyEdge(15, 48);
    std::cout << fes;
    fes.clear();

    std::cout << "\nResult of getNodesByBoundaryId(1) function:\n";
    nodes = loader->getNodesByBoundaryId(1);
    std::cout << nodes;
    nodes.clear();

    std::cout << "\nResult of getFEsByMaterialId(1) function:\n";
    fes = loader->getFEsByMaterialId(1);
    std::cout << fes;
    fes.clear();

    std::cout << "\nResult of getBFEsByBoundaryId(1) function:\n";
    bfes = loader->getBFEsByBoundaryId(1);
    std::cout << bfes;
    bfes.clear();
}


int main(int argc, char *argv[]) {
    auto *loader = new AneuMeshLoader;
    std::string path = "/home/nikitast/Documents/CLionProjects/cpp-lab1/cube.mesh";
    testMeshLoader(loader, path);
    return 0;
}