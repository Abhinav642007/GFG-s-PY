class Solution:
    def largest(self, arr):

        maxi = arr[0]

        for i in range(len(arr)):
            if arr[i] > maxi:
                maxi = arr[i]

        return maxi