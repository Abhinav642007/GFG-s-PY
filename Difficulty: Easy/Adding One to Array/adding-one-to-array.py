class Solution:
    def addOne(self, arr):

        carry = 1

        for i in range(len(arr) - 1, -1, -1):

            total = arr[i] + carry

            arr[i] = total % 10

            carry = total // 10

        if carry:
            arr.insert(0, carry)

        return arr