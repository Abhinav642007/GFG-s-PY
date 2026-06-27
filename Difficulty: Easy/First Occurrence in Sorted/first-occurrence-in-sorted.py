class Solution:
    def firstSearch(self, arr, k):

        low = 0
        high = len(arr) - 1
        ans = -1

        while low <= high:

            mid = (low + high) // 2

            if arr[mid] == k:
                ans = mid          # Index store karo
                high = mid - 1     # Left side search karo

            elif arr[mid] < k:
                low = mid + 1      # Right side jao

            else:
                high = mid - 1     # Left side jao

        return ans