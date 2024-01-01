#include <vector>
#include <limits>
#include <cmath>

class KDTreeNode {
public:
    std::vector<float> point;
    int id;
    KDTreeNode *left, *right;

    KDTreeNode(std::vector<float> point, int id) : point(point), id(id), left(nullptr), right(nullptr) {}
};

class KDTree {
private:
    KDTreeNode* root;

    KDTreeNode* insertRec(KDTreeNode* node, const std::vector<float>& point, int id, unsigned depth) {
        if (node == nullptr) return new KDTreeNode(point, id);

        unsigned cd = depth % 256; // Based you your need you can replace 256 with the dimension of your point
        // for example this is created in mind to work with https://catalog.ngc.nvidia.com/orgs/nvidia/teams/tao/models/reidentificationnet
        // which has 256 dimensions
        if (point[cd] < node->point[cd])
            node->left = insertRec(node->left, point, id, depth + 1);
        else
            node->right = insertRec(node->right, point, id, depth + 1);

        return node;
    }

    void nearestNeighborRec(KDTreeNode* node, const std::vector<float>& point, unsigned depth, KDTreeNode*& best, float& bestDist) {
        if (node == nullptr) return;

        float dist = euclideanDistance(point, node->point);
        if (dist < bestDist) {
            bestDist = dist;
            best = node;
        }

        unsigned cd = depth % 256;
        KDTreeNode* next = (point[cd] < node->point[cd]) ? node->left : node->right;
        KDTreeNode* other = (point[cd] < node->point[cd]) ? node->right : node->left;

        nearestNeighborRec(next, point, depth + 1, best, bestDist);

        if (fabs(point[cd] - node->point[cd]) < bestDist)
            nearestNeighborRec(other, point, depth + 1, best, bestDist);
    }

    float euclideanDistance(const std::vector<float>& a, const std::vector<float>& b) {
        float sum = 0;
        for (size_t i = 0; i < a.size(); i++) {
            sum += (a[i] - b[i]) * (a[i] - b[i]);
        }
        return sqrt(sum);
    }

public:
    KDTree() : root(nullptr) {}

    void insert(const std::vector<float>& point, int id) {
        root = insertRec(root, point, id, 0);
    }

    int findNearest(const std::vector<float>& point) {
        KDTreeNode* best = nullptr;
        float bestDist = std::numeric_limits<float>::max();
        nearestNeighborRec(root, point, 0, best, bestDist);
        return best ? best->id : -1;
    }
};
