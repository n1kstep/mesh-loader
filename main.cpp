#include "AneuMeshLoader.h"
#include <algorithm>


int main(int argc, char *argv[]) {
    AneuMeshLoader loader;
    loader.loadMesh("/home/nikitast/Downloads/cube.mesh");
    return 0;
}