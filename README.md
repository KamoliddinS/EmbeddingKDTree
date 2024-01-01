
# K-Dimensional Tree for 256-Dimensional Embeddings

## Description
This repository contains a C++ implementation of a k-dimensional tree (k-d tree) specifically designed for handling 256-dimensional embeddings. The implementation is tailored for applications requiring efficient nearest neighbor searches in high-dimensional spaces, such as image processing and machine learning tasks in the Nvidia DeepStream framework.

## Features
- **K-D Tree Implementation**: A basic, yet efficient k-d tree for handling 256-dimensional data points.
- **Nearest Neighbor Search**: Quickly find the closest point in the tree to a given 256-dimensional point.
- **Embedding to ID Mapping**: Efficiently map a 256-dimensional embedding to a corresponding ID.

## Installation
Clone the repository to your local machine:

```bash
git clone https://github.com/KamoliddinS/EmbeddingKDTree.git
cd EmbeddingKDTree
```

## Usage
Include the `kdtree.hpp` in your C++ project. Here's a simple example to demonstrate usage:

```cpp
#include "kdtree.hpp"

int main() {
    // Create a k-d tree instance
    KDTree tree;

    // Insert embeddings with corresponding IDs
    tree.insert({/* 256-dimensional embedding here */}, /* ID here */);

    // Search for the nearest embedding
    int nearestId = tree.findNearest({/* 256-dimensional embedding here */});

    return 0;
}
```
>Note: This project created in mind for reid applications, https://catalog.ngc.nvidia.com/orgs/nvidia/teams/tao/models/reidentificationnet

## Integration with Nvidia DeepStream
To integrate this k-d tree into the Nvidia DeepStream framework, ensure thread safety and consider GPU optimization based on your specific use case.

## Contributing
Contributions to enhance this implementation, including performance optimizations, are welcome. Please follow the standard pull request process for this repository.

## License
[MIT License](LICENSE)

