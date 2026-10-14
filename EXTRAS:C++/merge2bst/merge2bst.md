# Merge Two BSTs — C++ Solution

## Problem Statement

Given the roots of two Binary Search Trees (BSTs), merge them into a single sorted array containing all elements from both trees.

**Problem Link:** [GeeksforGeeks — Merge Two BSTs](https://www.geeksforgeeks.org/problems/merge-two-bst-s/1)

### Example

**Input:**

```text
BST 1:          BST 2:

    3               4
   / \             / \
  1   5           2   6
```

**Output:**

```text
[1, 2, 3, 4, 5, 6]
```

**Explanation:** The elements of both BSTs are combined into a single sorted array.

---

## Intuition

In a Binary Search Tree, inorder traversal (Left → Root → Right) produces elements in sorted order.

Instead of storing the inorder traversal of both trees in separate arrays, we can use two stacks to traverse both BSTs simultaneously and select the smaller available element.

This approach reduces auxiliary space usage.

---

## Approach: Two Stacks + Inorder Traversal

1. Create two stacks, `s1` and `s2`.
2. Push the leftmost path of each BST onto its respective stack.
3. Compare the top elements of both stacks.
4. Pop the smaller element and append its value to the result.
5. Move to the right subtree of the popped node.
6. Repeat until both trees and stacks are exhausted.
7. Return the merged sorted array.

---

## C++ Solution

```cpp
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

            // Select the smaller available element
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
```

---

## Dry Run

Consider two BSTs:

```text
BST 1:          BST 2:

    3               4
   / \             / \
  1   5           2   6
```

Their inorder sequences are:

```text
BST 1: [1, 3, 5]
BST 2: [2, 4, 6]
```

| Step | Selected Value | Result |
|---|---:|---|
| 1 | 1 | `[1]` |
| 2 | 2 | `[1, 2]` |
| 3 | 3 | `[1, 2, 3]` |
| 4 | 4 | `[1, 2, 3, 4]` |
| 5 | 5 | `[1, 2, 3, 4, 5]` |
| 6 | 6 | `[1, 2, 3, 4, 5, 6]` |

**Final Output:**

```text
[1, 2, 3, 4, 5, 6]
```

---

## Complexity Analysis

Let `n` and `m` be the number of nodes in the two BSTs, and `h1` and `h2` be their heights.

| Complexity | Value |
|---|---|
| Time | `O(n + m)` |
| Auxiliary Space | `O(h1 + h2)` |
| Output Space | `O(n + m)` |

Each node is pushed and popped from its stack exactly once.

---

## Key Concepts

- Binary Search Tree (BST)
- Inorder Traversal
- Iterative Tree Traversal
- Stack Data Structure
- Merging Sorted Sequences
- Time and Space Complexity

---

## Interview Questions

### 1. Why does inorder traversal work for a BST?

Because inorder traversal visits the nodes in sorted order.

### 2. Why use two stacks?

To simulate both inorder traversals simultaneously without storing two separate sorted arrays.

### 3. Can this problem be solved using recursion?

Yes. Perform inorder traversal on both trees, store their values in separate arrays, and merge the arrays using two pointers.

### 4. What is the main optimization?

The two-stack solution avoids two intermediate inorder arrays and merges elements while traversing the trees.

---

## Similar Problems

- [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)
- [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
- [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)

---

## Conclusion

The two-stack approach merges two BSTs into a sorted array in `O(n + m)` time using `O(h1 + h2)` auxiliary stack space.

**Key Insight:** Combine inorder traversal with the merging technique used for sorted arrays.
