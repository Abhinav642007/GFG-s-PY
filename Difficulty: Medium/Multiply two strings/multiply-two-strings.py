class Solution:
    def multiplyStrings(self, s1, s2):

        sign = 1

        if s1[0] == '-':
            sign *= -1
            s1 = s1[1:]

        if s2[0] == '-':
            sign *= -1
            s2 = s2[1:]

        # Remove leading zeros
        s1 = s1.lstrip('0')
        s2 = s2.lstrip('0')

        # If any string becomes empty, answer is 0
        if s1 == "" or s2 == "":
            return "0"

        ans = int(s1) * int(s2)

        if sign == -1:
            return "-" + str(ans)

        return str(ans)