# LeetCode 905 — Sort Array By Parity

## 🔥 Share My Solution

### Problem

Given an integer array `nums`, move all **even integers** to the beginning of the array and all **odd integers** to the end.

The relative order of even or odd numbers does **not** need to be preserved.

### Example

```text
Input:
[3, 1, 2, 4]

Output:
[2, 4, 3, 1]

```

Another valid output could be:

```text
[4, 2, 1, 3]
```

Both are correct because:

- Every even number is on the left.
- Every odd number is on the right.
- The order does not matter.

---

# 🧠 Intuition

Think of the array as two sections:

```text
EVEN NUMBERS | ODD NUMBERS
```

We use two pointers:

```text
left  → starts from the beginning
right → starts from the end
```

Our rules are simple:

1. If `nums[left]` is even, it is already in the correct place → move `left`.
2. If `nums[right]` is odd, it is already in the correct place → move `right`.
3. Otherwise:
   - left has an odd number
   - right has an even number
   - swap them.

---

# 🔍 Step-by-Step Dry Run

Consider:

```text
nums = [3, 1, 2, 4]
```

Initially:

```text
left = 0
right = 3

       L           R
       ↓           ↓
[ 3, 1, 2, 4 ]
```

### Step 1

`nums[left] = 3`

3 is odd, so it is in the wrong place.

Now check `nums[right] = 4`.

4 is even, so it is also in the wrong place for the right side.

Swap:

```text
[4, 1, 2, 3]
```

Move both pointers:

```text
left++
right--
```

Now:

```text
left = 1
right = 2
```

---

### Step 2

```text
[4, 1, 2, 3]
    L     R
    ↓     ↓
```

`nums[left] = 1`

1 is odd → wrong on the left.

`nums[right] = 2`

2 is even → wrong on the right.

Swap:

```text
[4, 2, 1, 3]
```

Move pointers:

```text
left = 2
right = 1
```

Now:

```text
left >= right
```

Stop.

### Final Answer

```text
[4, 2, 1, 3]
```

Check:

```text
4 → even ✅
2 → even ✅
1 → odd  ✅
3 → odd  ✅
```

---

# 💡 Why Does This Work?

At every step:

- Everything before `left` is already correctly placed as even.
- Everything after `right` is already correctly placed as odd.
- We only need to fix the middle section.

So the pointers continuously reduce the unsolved part of the array.

---

# Approach 1 — Two Pointer

## C++

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {

            // Even number is already correct on the left
            if (nums[left] % 2 == 0) {
                left++;
            }

            // Odd number is already correct on the right
            else if (nums[right] % 2 != 0) {
                right--;
            }

            // Left has odd and right has even
            else {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }

        return nums;
    }
};
```

---

## Java

```java
class Solution {
    public int[] sortArrayByParity(int[] nums) {

        int left = 0;
        int right = nums.length - 1;

        while (left < right) {

            // Even number is already in the correct place
            if (nums[left] % 2 == 0) {
                left++;
            }

            // Odd number is already in the correct place
            else if (nums[right] % 2 != 0) {
                right--;
            }

            // Left has odd and right has even
            else {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;

                left++;
                right--;
            }
        }

        return nums;
    }
}
```

---

## Python

```python
class Solution:
    def sortArrayByParity(self, nums):

        left = 0
        right = len(nums) - 1

        while left < right:

            # Even number is already correct
            if nums[left] % 2 == 0:
                left += 1

            # Odd number is already correct
            elif nums[right] % 2 != 0:
                right -= 1

            # Left has odd and right has even
            else:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1

        return nums
```

---

# 🧪 Another Example

```text
Input:
[2, 4, 1, 3, 6, 8, 5]
```

Start:

```text
[2, 4, 1, 3, 6, 8, 5]
 ↑                    ↑
 L                    R
```

`2` is even → move `L`.

```text
[2, 4, 1, 3, 6, 8, 5]
    ↑                 ↑
    L                 R
```

`4` is even → move `L`.

```text
[2, 4, 1, 3, 6, 8, 5]
       ↑              ↑
       L              R
```

Left = `1` (odd), right = `5` (odd).

Right is already correct → move `R`.

```text
[2, 4, 1, 3, 6, 8, 5]
       ↑           ↑
       L           R
```

Right = `8` (even).

Now:

- Left = odd ❌
- Right = even ❌

Swap:

```text
[2, 4, 8, 3, 6, 1, 5]
```

Continue until pointers meet.

One possible final answer:

```text
[2, 4, 8, 6, 3, 1, 5]
```

---

# ⏱️ Time Complexity

## O(n)

Why?

Each pointer moves only in one direction.

```text
left  → → → →
right ← ← ← ←
```

Together, they scan the array at most a constant number of times.

Therefore:

```text
Time = O(n)
```

---

# 💾 Space Complexity

## O(1)

We are modifying the array in-place.

We only use:

```text
left
right
temp
```

No extra array is created.

Therefore:

```text
Space = O(1)
```

---

# 🎯 Important Concept

This problem teaches:

- Two Pointers
- In-place array modification
- Partitioning
- Swapping
- Parity checking

The main pattern is:

```text
Correct element → move pointer
Wrong elements on both sides → swap
```

---

# 🧠 Pattern to Remember

Whenever a problem says something like:

> Put all elements satisfying condition A on one side and the remaining elements on the other side.

Think:

```text
TWO POINTERS
```

Example:

```text
Even | Odd
Negative | Positive
0 | Non-zero
Small | Large
```

---

# ⚠️ Common Mistakes

### 1. Using `nums[left] % 2 == 1`

This works for positive odd numbers, but for negative integers in languages such as C++/Java, `% 2` can be negative.

For this problem the values are non-negative, so it is fine under the given constraints, but a robust parity check is:

```cpp
nums[left] % 2 != 0
```

for odd.

---

### 2. Forgetting to move pointers after swapping

After:

```cpp
swap(nums[left], nums[right]);
```

we should do:

```cpp
left++;
right--;
```

Otherwise we can repeatedly inspect the same positions.

---

### 3. Thinking the output must have the same order

The problem does **not** require stable ordering.

For:

```text
[3, 1, 2, 4]
```

Both are valid:

```text
[2, 4, 3, 1]
```

and

```text
[4, 2, 1, 3]
```

---

# 🎤 Interview Explanation — 30 Seconds

> I use two pointers, one from the left and one from the right. If the left element is even, it is already in the correct position, so I move the left pointer. If the right element is odd, it is already correctly placed, so I move the right pointer. When the left contains an odd number and the right contains an even number, I swap them and move both pointers. This partitions the array in-place with O(n) time and O(1) extra space.

---

# 🎤 Interview Questions & Answers

## Q1. Why are two pointers useful here?

Because we need to separate the array into two groups:

```text
Even | Odd
```

One pointer handles the left side and the other handles the right side.

---

## Q2. Why do we move `left` when the number is even?

Because even numbers belong on the left.

So the element is already correct.

```cpp
if (nums[left] % 2 == 0)
    left++;
```

---

## Q3. Why do we move `right` when the number is odd?

Because odd numbers belong on the right.

So that element is already correct.

```cpp
else if (nums[right] % 2 != 0)
    right--;
```

---

## Q4. When do we swap?

When:

```text
left = odd
right = even
```

Both elements are on the wrong side.

So:

```cpp
swap(nums[left], nums[right]);
```

---

## Q5. Is the relative order preserved?

No.

This is an **unstable partition**.

The problem only requires even numbers before odd numbers.

---

## Q6. Can we solve it using an extra array?

Yes.

For example:

```text
First put all evens
Then put all odds
```

But that would require:

```text
O(n) extra space
```

The two-pointer solution is better because it works in:

```text
O(1) extra space
```

---

## Q7. What is the stopping condition?

```cpp
while (left < right)
```

When:

```text
left >= right
```

there is nothing left to partition.

---

## Q8. What is the main pattern?

**Two Pointer + Partition**

---

# 🔥 Connection With Your Previous Negative Partition Problem

Your previous problem was:

```text
Negative | Positive/Zero
```

This one is:

```text
Even | Odd
```

The logic is almost identical.

### Negative partition

```text
Left wants negative
Right wants positive/zero
```

### Parity partition

```text
Left wants even
Right wants odd
```

So you can think:

```text
          PARTITION
              ↓
        TWO POINTERS
          ↙       ↘
      LEFT        RIGHT
       ↓            ↓
   desired       desired
   element       element
       ↓            ↓
    move          move
              OR
             swap
```

---

# 🚀 Similar LeetCode Problems

After LeetCode 905, practice:

1. **LeetCode 922 — Sort Array By Parity II**
2. **LeetCode 283 — Move Zeroes**
3. **LeetCode 2149 — Rearrange Array Elements by Sign**
4. **LeetCode 75 — Sort Colors**
5. **LeetCode 27 — Remove Element**

Recommended order:

```text
905
 ↓
922
 ↓
283
 ↓
2149
 ↓
75
```

---

# 📝 Quick Revision

Remember just this:

```cpp
while (left < right) {

    if (left element is already correct)
        left++;

    else if (right element is already correct)
        right--;

    else
        swap(left, right);
}
```

For this problem:

```text
LEFT  → EVEN
RIGHT → ODD
```

### Final Complexity

```text
Time  : O(n)
Space : O(1)
```

---

## ⭐ Interview Takeaway

**LeetCode 905 is an important beginner two-pointer partition problem.**

Once you understand this, you should be able to recognize the same pattern in:

```text
Even / Odd
Negative / Positive
Zero / Non-zero
0 / 1 / 2
Smaller / Larger
```

The most important thing is not memorizing the code — understand **why each pointer moves and when swapping happens**.
