class Solution:
    def getMinMax(self, arr):

        return [min(arr), max(arr)]
        
# class Solution:
#     def getMinMax(self, arr):

#         mini = arr[0]
#         maxi = arr[0]

#         for i in range(len(arr)):
#             if arr[i] < mini:
#                 mini = arr[i]

#             if arr[i] > maxi:
#                 maxi = arr[i]

#         return [mini, maxi]