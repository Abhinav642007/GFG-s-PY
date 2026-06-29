class Solution:
	def arraySum(self, arr):
   		# code here
        sum=0
        for i in range(len(arr)):
            sum=sum+arr[i]
        return sum