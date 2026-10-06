# 🌳 Kth Largest Element in a BST

## 📌 Problem

Given the root of a **Binary Search Tree (BST)** and an integer `k`, find the **kth largest element** in the BST.

---

## 💡 Intuition

In a BST:

```text
Left < Root < Right
```

Normal inorder traversal gives elements in ascending order:

```text
Left → Root → Right
```

For the **kth largest**, we simply reverse the traversal:

```text
Right → Root → Left
```

The kth node visited is the kth largest element.

---

## 🧠 Approach

1. Traverse the **right subtree first**.
2. Visit the current node and increment `count`.
3. If `count == k`, return the current node's value.
4. Otherwise, traverse the left subtree.
5. Stop immediately when the answer is found.

---

## 🌲 Example

```text
        5
       / \
      3   7
     / \ / \
    2  4 6  8
```

Reverse inorder:

```text
8 → 7 → 6 → 5 → 4 → 3 → 2
```

For `k = 3`:

```text
8 → count = 1
7 → count = 2
6 → count = 3 ✅
```

**Answer = 6**

---

## 💻 C++ Solution

```cpp
class Solution {
  public:

    int count = 0;

    int kthLargest(Node* root, int k) {

        // If tree is empty
        if (root == NULL)
            return -1;

        // Go right first because larger elements
        // are present in the right subtree
        int right = kthLargest(root->right, k);

        // If kth largest is already found,
        // return it immediately
        if (right != -1)
            return right;

        // Visit current node
        count++;

        // If this is the kth visited node,
        // it is the kth largest element
        if (count == k)
            return root->data;

        // Go left
        return kthLargest(root->left, k);
    }
};
```

---

## 🔍 Dry Run

For:

```text
        5
       / \
      3   7
     / \ / \
    2  4 6  8
```

and `k = 3`:

| Node | Count |
|---|---:|
| 8 | 1 |
| 7 | 2 |
| 6 | 3 ✅ |

At node `6`:

```cpp
if (count == k)
    return root->data;
```

Since `3 == 3`, we return `6`.

The remaining nodes are not traversed.

---

## 🔄 Kth Smallest vs Kth Largest

| Problem | Traversal |
|---|---|
| Kth Smallest | Left → Root → Right |
| Kth Largest | Right → Root → Left |

### 🧠 Memory Trick

```text
Smallest → LEFT first
Largest  → RIGHT first
```

---

## ⏱️ Complexity

Let `H` be the height of the BST.

### Time Complexity

```text
O(H + k)
```

Worst case:

```text
O(N)
```

### Space Complexity

```text
O(H)
```

because of the recursive call stack.

Balanced BST:

```text
O(log N)
```

Skewed BST:

```text
O(N)
```

---

## 🎯 Interview Explanation

> Since a BST's inorder traversal gives elements in ascending order, I use reverse inorder traversal — right, root, left — to get elements in descending order. I maintain a counter, and when the counter reaches `k`, the current node is the kth largest element. I stop immediately once the answer is found.

---

## ⚠️ Common Mistakes

- Using `Left → Root → Right` for kth largest.
- Forgetting to increment `count`.
- Continuing traversal after finding the answer.
- Confusing `root->data` with `root->val` depending on the platform.
- Not using the BST property.

---

## 🔥 Core Pattern

```text
BST
 ↓
Reverse Inorder
 ↓
Right → Root → Left
 ↓
Count nodes
 ↓
count == k
 ↓
Kth Largest
```

### ⭐ One-line memory trick

**Kth Largest = Reverse Inorder + Counter**
