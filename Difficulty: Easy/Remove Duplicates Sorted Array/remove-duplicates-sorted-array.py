class Solution:
    def removeDuplicates(self, arr):
        # code here 
        if len(arr)==0:
            return []
            
        j=0
        
        for i in range(1,len(arr)):
            if arr[i]!=arr[j]:
                j+=1
                arr[j]=arr[i]
            
        return arr[:j+1]