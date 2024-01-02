#include "kdtree.hpp"
#include <iostream>
int main() {
    // Create a k-d tree instance
    KDTree tree;

    // Insert embeddings with corresponding IDs
    tree.insert({0}, 0);

    // Search for the nearest embedding
    int nearestId = tree.findNearest({0});

    std::cout << "Nearest ID: " << nearestId << std::endl;
    return 0;
}