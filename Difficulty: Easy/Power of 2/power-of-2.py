import math

class Solution:
    def isPowerofTwo(self, n):

        if n <= 0:
            return False

        return math.log2(n).is_integer()