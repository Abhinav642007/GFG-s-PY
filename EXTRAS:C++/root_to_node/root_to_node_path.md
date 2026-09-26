# Root to Node Path in Binary Tree

## Problem

Given the root of a binary tree and a target value `B`, find the path
from the **root node to the target node**.

Return the path as a `vector<int>`.

### Example

``` text
        1
       / \
      2   3
     / \
    4   5
```

Target = `5`

Output:

``` text
[1, 2, 5]
```

------------------------------------------------------------------------

# Core Idea

We use **DFS (Depth First Search) + Backtracking**.

At every node:

1.  If the node is `NULL`, the target does not exist in this path →
    return `false`.
2.  Add the current node to `arr`.
3.  If the current node is the target → return `true`.
4.  Search the **left subtree**.
5.  If left does not contain the target, search the **right subtree**.
6.  If neither subtree contains the target, remove the current node
    using `pop_back()` and return `false`.

The important idea is:

> Add a node when entering it, and remove it when that node does not
> lead to the target.

------------------------------------------------------------------------

# Code

``` cpp
class Solution {
public:

    bool getPath(TreeNode* root, vector<int>& arr, int x) {

        // If node is NULL, target is not found here
        if (!root)
            return false;

        // Add current node to the path
        arr.push_back(root->val);

        // Target found
        if (root->val == x)
            return true;

        // Search left or right subtree
        if (getPath(root->left, arr, x) ||
            getPath(root->right, arr, x)) {
            return true;
        }

        // Target was not found in this subtree
        // Remove current node while backtracking
        arr.pop_back();

        return false;
    }

public:

    vector<int> solve(TreeNode* A, int B) {

        vector<int> arr;

        if (A == NULL)
            return arr;

        getPath(A, arr, B);

        return arr;
    }
};
```

------------------------------------------------------------------------

# Detailed Explanation

## 1. NULL Check

``` cpp
if (!root)
    return false;
```

If `root == NULL`, there is no node to search.

So this branch cannot contain the target.

------------------------------------------------------------------------

## 2. Add Current Node

``` cpp
arr.push_back(root->val);
```

Whenever we visit a node, we add it to the current path.

For example:

``` text
1 → 2 → 5
```

The array becomes:

``` text
[1, 2, 5]
```

------------------------------------------------------------------------

## 3. Check Target

``` cpp
if (root->val == x)
    return true;
```

If the current node is the target, our path is complete.

Example:

``` text
Target = 5

arr = [1, 2, 5]
```

Return `true`.

------------------------------------------------------------------------

# 4. Search Left and Right

``` cpp
if (getPath(root->left, arr, x) ||
    getPath(root->right, arr, x)) {
    return true;
}
```

This is the most important part.

### Meaning

First search the left subtree.

``` cpp
getPath(root->left, arr, x)
```

If it returns `true`, the target has been found, so because of `||`, the
right subtree is **not searched**.

If left returns `false`, then the right subtree is searched:

``` cpp
getPath(root->right, arr, x)
```

If either side finds the target, return `true`.

------------------------------------------------------------------------

# Why `||` is Used

Consider:

``` text
        1
       / \
      2   3
     / \
    4   5
```

Target = `5`

At node `2`:

``` cpp
getPath(4, arr, 5) || getPath(5, arr, 5)
```

First:

``` cpp
getPath(4, ...)
```

returns:

``` text
false
```

Therefore, the second part executes:

``` cpp
getPath(5, ...)
```

It finds the target and returns:

``` text
true
```

So:

``` text
false || true
       ↓
      true
```

The `true` then propagates back to node `1`.

------------------------------------------------------------------------

# 5. Backtracking

``` cpp
arr.pop_back();
```

This executes only when the target was **not found** in the current
subtree.

Example:

``` text
        1
       /
      2
     /
    4
```

Target = `5`

We initially have:

``` text
[1, 2, 4]
```

At node `4`, target `5` is not found.

So:

``` cpp
arr.pop_back();
```

removes `4`.

Now:

``` text
[1, 2]
```

We can then explore another branch without keeping `4` in the path.

This is called **backtracking**.

------------------------------------------------------------------------

# Complete Dry Run

Tree:

``` text
        1
       / \
      2   3
     / \
    4   5
```

Target:

``` text
5
```

### Call 1

``` cpp
getPath(1, arr, 5)
```

``` text
arr = [1]
```

`1 != 5`

Search left:

``` cpp
getPath(2, arr, 5)
```

------------------------------------------------------------------------

### Call 2

``` text
arr = [1, 2]
```

`2 != 5`

Search left:

``` cpp
getPath(4, arr, 5)
```

------------------------------------------------------------------------

### Call 3

``` text
arr = [1, 2, 4]
```

`4 != 5`

Node `4` has no useful child.

Target not found.

Backtrack:

``` cpp
arr.pop_back();
```

Now:

``` text
arr = [1, 2]
```

Return `false`.

------------------------------------------------------------------------

### Back to Node 2

Left returned `false`.

Therefore:

``` cpp
getPath(2->right, arr, 5)
```

is executed.

That is:

``` cpp
getPath(5, arr, 5)
```

------------------------------------------------------------------------

### Call 4

``` text
arr = [1, 2, 5]
```

Now:

``` cpp
5 == 5
```

Return:

``` text
true
```

------------------------------------------------------------------------

### True Propagation

At node `2`:

``` text
false || true
       ↓
      true
```

Return `true`.

At node `1`:

``` text
true
```

Return `true`.

Final answer:

``` text
[1, 2, 5]
```

------------------------------------------------------------------------

# Why Don't We Pop When Target Is Found?

When:

``` cpp
if (root->val == x)
    return true;
```

we immediately return.

We **do not** execute:

``` cpp
arr.pop_back();
```

because we want the target node to remain in `arr`.

For target `5`:

``` text
[1, 2, 5]
```

This is exactly the answer we need.

------------------------------------------------------------------------

# Why `arr` Is Passed by Reference

``` cpp
vector<int>& arr
```

The `&` means all recursive calls use the **same vector**.

Without reference:

``` cpp
vector<int> arr
```

a new copy would be created for every call, which would be inefficient
and would not allow the same path to be maintained through recursion.

------------------------------------------------------------------------

# Algorithm

1.  Start from the root.
2.  If the current node is `NULL`, return `false`.
3.  Add the current node's value to `arr`.
4.  If current node equals target, return `true`.
5.  Recursively search the left subtree.
6.  If left fails, recursively search the right subtree.
7.  If either search succeeds, return `true`.
8.  If both fail, remove the current node from `arr`.
9.  Return `false`.

------------------------------------------------------------------------

# Complexity Analysis

Let:

-   `N` = number of nodes
-   `H` = height of the tree

## Time Complexity

``` text
O(N)
```

In the worst case, we may visit every node once.

## Auxiliary Space Complexity

``` text
O(H)
```

The recursion stack can contain at most `H` nodes.

-   Balanced tree: `H = O(log N)`
-   Skewed tree: `H = O(N)`

## Output / Path Space

The returned path can contain up to `H` nodes:

``` text
O(H)
```

Therefore, if counting the returned result as well:

``` text
O(H)
```

The main working auxiliary space is the recursion stack plus the path
vector, both bounded by the tree height.

------------------------------------------------------------------------

# Important Interview Point

### Why does `pop_back()` happen only after both recursive calls fail?

Because if either subtree finds the target:

``` cpp
if (getPath(left, arr, x) ||
    getPath(right, arr, x))
    return true;
```

we immediately return `true`.

Therefore, `pop_back()` is reached only when:

``` text
left = false
right = false
```

meaning the current node is not part of the final root-to-target path.

------------------------------------------------------------------------

# Common Mistakes

### 1. Forgetting `push_back()`

``` cpp
arr.push_back(root->val);
```

Without this, the current node will not be included in the path.

### 2. Popping before returning true

Wrong:

``` cpp
if (root->val == x) {
    arr.pop_back();
    return true;
}
```

This removes the target from the answer.

### 3. Forgetting backtracking

If we don't use:

``` cpp
arr.pop_back();
```

failed branches remain in the vector.

### 4. Searching both sides unnecessarily

Using:

``` cpp
getPath(left, arr, x);
getPath(right, arr, x);
```

without checking the result can continue searching even after finding
the target.

Using:

``` cpp
getPath(left, arr, x) || getPath(right, arr, x)
```

allows short-circuit evaluation.

------------------------------------------------------------------------

# Pattern

**Binary Tree DFS + Backtracking**

This pattern is useful for:

-   Root to Node Path
-   Root to Leaf Paths
-   Path Sum
-   Finding paths satisfying a condition
-   Lowest Common Ancestor
-   Other tree path problems

------------------------------------------------------------------------

# Interview Explanation --- 30 Seconds

> "I use DFS with backtracking. Whenever I visit a node, I push its
> value into the path. If it is the target, I return true. Otherwise, I
> recursively search the left and right subtrees. If either subtree
> finds the target, I propagate true back to the root. If neither
> subtree contains the target, I remove the current node using
> `pop_back()` because it is not part of the valid path."

------------------------------------------------------------------------

# Key Takeaway

Remember this template:

``` cpp
if (!root)
    return false;

arr.push_back(root->val);

if (root->val == target)
    return true;

if (getPath(root->left, arr, target) ||
    getPath(root->right, arr, target))
    return true;

arr.pop_back();

return false;
```

### One-line logic

``` text
PUSH → CHECK → SEARCH → POP IF FAILED
```
