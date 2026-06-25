class Solution:
    def cost(self, arr):
        #code here
        n=len(arr)
        return ( (n - 1) * min(arr) )