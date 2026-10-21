
#include <bits/stdc++.h>
using namespace std;

/*
Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {

        Node* pre = nullptr;  // Inorder predecessor
        Node* suc = nullptr;  // Inorder successor

        Node* curr = root;    // Start from root

        while (curr != nullptr) {

            if (curr->data < key) {
                pre = curr;              // Possible predecessor
                curr = curr->right;      // Search right
            }
            else if (curr->data > key) {
                suc = curr;              // Possible successor
                curr = curr->left;       // Search left
            }
            else {
                // Target key found

                // Find predecessor in left subtree
                if (curr->left != nullptr) {
                    Node* temp = curr->left;

                    while (temp->right != nullptr) {
                        temp = temp->right;
                    }

                    pre = temp;
                }

                // Find successor in right subtree
                if (curr->right != nullptr) {
                    Node* temp = curr->right;

                    while (temp->left != nullptr) {
                        temp = temp->left;
                    }

                    suc = temp;
                }

                break;
            }
        }

        return {pre, suc};  // Predecessor first, successor second
    }
};
