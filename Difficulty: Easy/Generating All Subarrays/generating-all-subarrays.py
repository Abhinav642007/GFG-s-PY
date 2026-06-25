class Solution:
    def getSubArrays(self, arr):
        ans = []
        n = len(arr)

        for i in range(n):
            for j in range(i, n):
                ans.append(arr[i:j+1])

        return ans