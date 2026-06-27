class Solution:
    def peakElement(self, arr):

        n = len(arr)

        # Agar sirf ek element hai
        if n == 1:
            return 0

        # First element check
        if arr[0] >= arr[1]:
            return 0

        # Middle elements check
        for i in range(1, n - 1):
            if arr[i] >= arr[i - 1] and arr[i] >= arr[i + 1]:
                return i

        # Last element check
        return n - 1   