class Solution:
    def majorityElement(self, arr):

        freq = {}

        for x in arr:
            freq[x] = freq.get(x, 0) + 1

        for key in freq:
            if freq[key] > len(arr) // 2:
                return key

        return -1