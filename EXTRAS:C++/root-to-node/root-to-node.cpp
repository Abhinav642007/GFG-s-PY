#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

bool getPath(TreeNode* root, vector<int>& arr, int target) {

    // Node doesn't exist
    if (root == NULL)
        return false;

    // Add current node
    arr.push_back(root->val);

    // Target found
    if (root->val == target)
        return true;

    // Search left or right
    if (getPath(root->left, arr, target) ||
        getPath(root->right, arr, target)) {
        return true;
    }

    // Target not found in this subtree
    arr.pop_back();

    return false;
}

int main() {

    // Creating tree
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int target = 5;

    vector<int> path;

    getPath(root, path, target);

    // Print path with arrows
    for (int i = 0; i < path.size(); i++) {

        cout << path[i];

        if (i != path.size() - 1)
            cout << " -> ";
    }

    return 0;
}