class Solution:
    def checkStatus(self, a, b, flag):
        # code here
        if flag:
            return a<0 and b<0
        else:
            return (a<0 and b>=0) or (a>=0 and b<0)
            