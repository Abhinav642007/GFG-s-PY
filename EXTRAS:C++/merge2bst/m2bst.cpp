#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
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
    vector<int> merge(Node* r1, Node* r2) {
        stack<Node*> s1, s2;
        vector<int> ans;

        while (r1 || r2 || !s1.empty() || !s2.empty()) {

            // Push left nodes of BST 1
            while (r1) {
                s1.push(r1);
                r1 = r1->left;
            }

            // Push left nodes of BST 2
            while (r2) {
                s2.push(r2);
                r2 = r2->left;
            }

            // Take the smaller available element
            if (s2.empty() ||
                (!s1.empty() &&
                 s1.top()->data <= s2.top()->data)) {

                Node* curr = s1.top();
                s1.pop();

                ans.push_back(curr->data);
                r1 = curr->right;
            } else {
                Node* curr = s2.top();
                s2.pop();

                ans.push_back(curr->data);
                r2 = curr->right;
            }
        }

        return ans;
    }
};

int main() {
    // BST 1
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    // BST 2
    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    Solution sol;
    vector<int> result = sol.merge(root1, root2);

    cout << "Merged BST elements: ";
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}