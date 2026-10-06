#include <iostream>
using namespace std;

// Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:

    int count = 0;

    int kthLargest(Node* root, int k) {

        // Right subtree first
        if (root == nullptr)
            return -1;

        int right = kthLargest(root->right, k);

        // Answer already found
        if (right != -1)
            return right;

        // Visit current node
        count++;

        // Kth largest found
        if (count == k)
            return root->data;

        // Go to left subtree
        return kthLargest(root->left, k);
    }
};

int main() {

    /*
            5
           / \
          3   7
         / \ / \
        2  4 6  8
    */

    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(7);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(8);

    int k = 3;

    Solution obj;

    int ans = obj.kthLargest(root, k);

    cout << k << "th largest element = " << ans << endl;

    return 0;
}