class Solution:
    def isPerfectSquare(self, n: int) -> bool:

        for i in range(n+1):
            if i*i == n:
                return True

        return False