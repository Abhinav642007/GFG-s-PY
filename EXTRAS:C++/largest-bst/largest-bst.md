# Largest BST in a Binary Tree

## Problem Statement

Given a binary tree, find the size of the **largest subtree that is a
Binary Search Tree (BST)**.

A subtree must satisfy the BST property: - Every value in the left
subtree is smaller than the current node. - Every value in the right
subtree is greater than the current node. - Both left and right subtrees
must also be valid BSTs.

Return the number of nodes in the largest BST subtree.

## Approach: Postorder Traversal

Use recursion to process the left and right subtrees before processing
the current node.

For every subtree, return three pieces of information:

-   `mini`: Minimum value in the subtree.
-   `maxi`: Maximum value in the subtree.
-   `size`: Size of the BST represented by the subtree, or the largest
    BST size found within it if the subtree is invalid.

For a non-empty subtree to be a BST, the left and right subtrees must be
valid and:

``` text
left.maxi < root->data < right.mini
```

If the condition holds, combine both subtree sizes with the current
node. Otherwise, return the larger BST size from either child and
special boundary values so the parent cannot treat the invalid subtree
as a BST.

## C++ Solution (GFG)

``` cpp
class Solution {
  public:
    struct Info {
        int mini, maxi, size;

        Info(int mn, int mx, int s) {
            mini = mn;
            maxi = mx;
            size = s;
        }
    };

    Info solve(Node* root) {
        // An empty subtree is a valid BST of size 0.
        if (root == NULL)
            return Info(INT_MAX, INT_MIN, 0);

        // Process the left and right subtrees first.
        Info left = solve(root->left);
        Info right = solve(root->right);

        // If the current subtree is a BST, combine its nodes.
        if (root->data > left.maxi &&
            root->data < right.mini) {

            int currSize = left.size + right.size + 1;

            return Info(
                min(root->data, left.mini),
                max(root->data, right.maxi),
                currSize
            );
        }

        // Invalid subtree: preserve the largest BST in either child.
        // These boundaries ensure the parent cannot treat this
        // subtree as a valid BST.
        return Info(INT_MIN, INT_MAX,
                    max(left.size, right.size));
    }

    int largestBst(Node* root) {
        return solve(root).size;
    }
};
```

## Example

``` text
        10
       /  \
      5    15
     / \   / \
    1   8 7  20
```

The subtree rooted at `5` is a valid BST:

``` text
      5
     / \
    1   8
```

Its size is `3`. The subtree rooted at `15` is not a BST because `7` is
in the right subtree of `15`, but `7 < 15`.

**Output:**

``` text
3
```

## Complexity Analysis

-   **Time Complexity:** `O(N)` --- each node is processed once.
-   **Auxiliary Space:** `O(H)` --- recursion stack, where `H` is the
    height of the tree. In the worst case of a skewed tree, this can be
    `O(N)`.

## Key Takeaways

-   Use **postorder traversal**: solve left, solve right, then process
    the current node.
-   Track the minimum, maximum, and size for every subtree.
-   Checking only the immediate children is not enough; use the maximum
    of the entire left subtree and minimum of the entire right subtree.
-   The tree itself does not need to be a BST. The goal is to find its
    largest BST subtree.

## Pattern

**Binary Tree + Postorder DFS + Subtree Information**
