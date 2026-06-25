class Solution:
    def findTwoElement(self, arr):

        n = len(arr)
        d = {}

        # Count frequency
        for i in arr:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1

        repeating = -1
        missing = -1

        # Find repeating and missing
        for i in range(1, n + 1):
            if i not in d:
                missing = i
            elif d[i] == 2:
                repeating = i

        return [repeating, missing]