class Solution {
public:
    bool isSumOfConsecutive(int n) {

        // 1 cannot be represented
        if (n == 1)
            return false;

        // Power of 2 cannot be represented
        if ((n & (n - 1)) == 0)
            return false;

        return true;
    }
};