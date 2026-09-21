class Solution {
  public:

    // Check if node is a leaf
    bool isLeaf(Node* root) {
        return root->left == NULL && root->right == NULL;
    }

    // Add left boundary
    void leftBoundary(Node* root, vector<int>& ans) {

        Node* curr = root->left;

        while (curr) {

            if (!isLeaf(curr))
                ans.push_back(curr->data);

            // Prefer left, otherwise right
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    // Add all leaf nodes
    void leaves(Node* root, vector<int>& ans) {

        if (root == NULL)
            return;

        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }

        leaves(root->left, ans);
        leaves(root->right, ans);
    }

    // Add right boundary
    void rightBoundary(Node* root, vector<int>& ans) {

        vector<int> temp;

        Node* curr = root->right;

        while (curr) {

            if (!isLeaf(curr))
                temp.push_back(curr->data);

            // Prefer right, otherwise left
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        // Reverse: bottom to top
        reverse(temp.begin(), temp.end());

        for (int x : temp)
            ans.push_back(x);
    }

    vector<int> boundaryTraversal(Node *root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        // Add root
        if (!isLeaf(root))
            ans.push_back(root->data);

        // 1. Left boundary
        leftBoundary(root, ans);

        // 2. Leaf nodes
        leaves(root, ans);

        // 3. Right boundary in reverse
        rightBoundary(root, ans);

        return ans;
    }
};