class Solution:
    def checkYear(self, n):
        if (n % 400 == 0) or (n % 4 == 0 and n % 100 != 0):
            return True
        else:
            return False