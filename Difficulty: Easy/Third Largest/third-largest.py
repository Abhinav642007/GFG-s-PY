class Solution:
    def thirdLargest(self,arr):
            # code here
        
        n = len(arr)
        
        if n < 3:
            return -1
        # Sort the array 
        arr.sort()
        
        # Return the third largest element 
        return arr[n - 3]

