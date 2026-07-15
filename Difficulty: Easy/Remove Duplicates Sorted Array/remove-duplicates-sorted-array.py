class Solution:
    def removeDuplicates(self, arr):
        # code here 
        seen=set()
        abc=[]
        for num in arr:
            if num not in seen:
                seen.add(num)
                abc.append(num)
        return abc
        