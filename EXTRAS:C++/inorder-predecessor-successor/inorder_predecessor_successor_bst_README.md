# Inorder Predecessor and Successor in a Binary Search Tree (BST)

## Problem Statement

Given the root of a Binary Search Tree (BST) and a target value `key`, find:

- **Inorder Predecessor (`pre`)**: the node with the greatest value strictly smaller than `key`.
- **Inorder Successor (`suc`)**: the node with the smallest value strictly greater than `key`.

If either value does not exist, its pointer should remain `nullptr`.

> **Note:** This README uses the common GeeksforGeeks-style `Node` structure with a `key` member. Some platforms use `data` or `val` instead; change `curr->key` to the member name used by your platform.

---

## Core Concept

An inorder traversal of a BST visits nodes in this order:

**Left → Root → Right**

Because of the BST property, inorder traversal visits the values in sorted, ascending order.

For example, the inorder traversal of this tree is:

```text
        8
       / \
      3   10
       \  /
        6 9

Inorder: 3, 6, 8, 9, 10
```

For `key = 8`:

- Predecessor is `6`, the value immediately before `8` in sorted order.
- Successor is `9`, the value immediately after `8` in sorted order.

## Approach

We use the BST ordering property to search efficiently without traversing every node.

### 1. Initialize the pointers

```cpp
pre = nullptr;
suc = nullptr;
Node* curr = root;
```

- `pre` stores the predecessor node.
- `suc` stores the successor node.
- `curr` points to the node currently being examined.
- Both answers begin as `nullptr` in case one does not exist.

### 2. Search for the target

While `curr` is not `nullptr`, compare `curr->key` with `key`.

- **If `curr->key < key`:** `curr` is a possible predecessor. Save it in `pre`, then move right to look for a closer (larger but still smaller) value.
- **If `curr->key > key`:** `curr` is a possible successor. Save it in `suc`, then move left to look for a closer (smaller but still larger) value.
- **Otherwise:** the target has been found. Check its left and right subtrees.

### 3. Find the predecessor when the target exists

If the target has a left subtree, the predecessor is the **rightmost node in that left subtree**.

1. Start at `curr->left`.
2. Keep moving to `temp->right` while a right child exists.
3. Store the final node in `pre`.

If there is no left subtree, the predecessor candidate already saved while searching is the answer.

### 4. Find the successor when the target exists

If the target has a right subtree, the successor is the **leftmost node in that right subtree**.

1. Start at `curr->right`.
2. Keep moving to `temp->left` while a left child exists.
3. Store the final node in `suc`.

If there is no right subtree, the successor candidate already saved while searching is the answer.

### 5. Return

Once the target is found and both sides have been checked, return from the function. If the search reaches `nullptr` without finding the target, the candidates saved during the search are returned through the reference parameters.

---

## C++ Solution (with Inline Comments)

```cpp
class Solution {
public:
    void findPreSuc(Node* root, Node*& pre,
                    Node*& suc, int key) {
        pre = nullptr;  // No predecessor found yet
        suc = nullptr;  // No successor found yet

        Node* curr = root;  // Start searching from the root

        while (curr) {  // Continue while the current node exists

            if (curr->key < key) {
                pre = curr;  // Current node is a predecessor candidate
                curr = curr->right;  // Look for a closer, larger candidate
            }
            else if (curr->key > key) {
                suc = curr;  // Current node is a successor candidate
                curr = curr->left;  // Look for a closer, smaller candidate
            }
            else {
                // The target key has been found

                if (curr->left) {
                    Node* temp = curr->left;  // Enter the left subtree

                    while (temp->right) {
                        temp = temp->right;  // Find its maximum value
                    }

                    pre = temp;  // Maximum of left subtree is predecessor
                }

                if (curr->right) {
                    Node* temp = curr->right;  // Enter the right subtree

                    while (temp->left) {
                        temp = temp->left;  // Find its minimum value
                    }

                    suc = temp;  // Minimum of right subtree is successor
                }

                return;  // Both answers have been determined
            }
        }
    }
};
```

### Understanding `curr->key`

`curr` is a pointer to a node. The arrow operator (`->`) accesses a member of the node that the pointer refers to.

```cpp
curr->key       // Read the key stored in the current node
curr->left      // Access the pointer to its left child
curr->right     // Access the pointer to its right child
```

`curr->key` is equivalent to `(*curr).key`.

For example, if `curr` points to the root node containing `8`, then `curr->key` is `8`.

### Understanding `Node*&`

The parameters `Node*& pre` and `Node*& suc` are **references to pointers**. This lets the function update the caller's pointer variables directly.

For example, `pre = temp;` changes the caller's `pre` pointer to point to the node found by the algorithm.

---

## Dry Run

Use this BST and set `key = 8`:

```text
        8
       / \
      3   10
       \  /
        6 9
```

| Step | Action | Result |
|---|---|---|
| 1 | Initialize `pre` and `suc` | Both are `nullptr` |
| 2 | Set `curr = root` | `curr->key = 8` |
| 3 | Compare `8` with `key = 8` | Target found |
| 4 | Go left from `8` to `3`, then right to `6` | `pre = 6` |
| 5 | Go right from `8` to `10`, then left to `9` | `suc = 9` |
| 6 | Return from the function | Predecessor `6`, successor `9` |

**Result:** `pre->key = 6` and `suc->key = 9`.

---

## Another Example: Target Is Not in the BST

Consider the BST:

```text
        8
       / \
      3   10
```

For `key = 9`:

1. Start at `8`. Since `8 < 9`, save `8` as the predecessor candidate and move right.
2. At `10`, since `10 > 9`, save `10` as the successor candidate and move left.
3. The left child is `nullptr`, so the search stops.

The target `9` is not present, but the closest values on either side are:

- Predecessor: `8`
- Successor: `10`

This is why the candidates are updated while searching, before the target is found.

---

## Why Does the Algorithm Work?

The BST property guarantees:

- All values in a node's left subtree are smaller than the node's value.
- All values in its right subtree are greater than the node's value.

During the search, whenever the current value is smaller than `key`, it can be a predecessor, and moving right may find a better candidate. Whenever the current value is greater than `key`, it can be a successor, and moving left may find a better candidate.

If the target is found, the rightmost node of its left subtree is the largest value below it, and the leftmost node of its right subtree is the smallest value above it. Therefore, the algorithm finds the nearest values on either side.

## Complexity Analysis

Let `h` be the height of the BST and `n` be the number of nodes.

- **Time Complexity: `O(h)`** — the search follows a single root-to-leaf path. Finding the rightmost or leftmost node also takes at most `O(h)` time. These traversals are sequential, so the overall complexity remains `O(h)`.
- **Auxiliary Space: `O(1)`** — only a constant number of pointers are used; the algorithm is iterative.

For a balanced BST, `h = O(log n)`, so the time complexity is `O(log n)`. For a skewed BST, `h = O(n)`, so the worst-case time complexity is `O(n)`.

## Common Mistakes

1. **Going in the wrong direction:** For a predecessor candidate, move right after saving a smaller value. For a successor candidate, move left after saving a larger value.
2. **Choosing the wrong subtree extreme:** The predecessor is the rightmost node of the left subtree; the successor is the leftmost node of the right subtree.
3. **Forgetting missing answers:** Initialize `pre` and `suc` to `nullptr`.
4. **Assuming the target must exist:** The search may end at `nullptr`; candidates collected along the way can still be valid, depending on the problem definition.
5. **Using the wrong node field:** Some platforms use `data` or `val` instead of `key`.
6. **Confusing a pointer with its value:** `curr` is a pointer; `curr->key` is the integer stored in that node.

## Quick Revision

- Inorder traversal: **Left → Root → Right**
- Predecessor: **largest value smaller than the target**
- Successor: **smallest value greater than the target**
- Predecessor in a target's left subtree: **rightmost node**
- Successor in a target's right subtree: **leftmost node**
- Time: **`O(h)`**
- Auxiliary space: **`O(1)`**
