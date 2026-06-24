class Solution:
    def leaders(self, arr):

        ans = []                 # leaders store karne ke liye list

        maxi = arr[-1]           # last element hamesha leader hota hai
                                # arr = [16,17,4,3,5,2]
                                # maxi = 2

        ans.append(maxi)         # ans = [2]

        for i in range(len(arr)-2, -1, -1):
            # len(arr)-2 = second last index
            # -1 = 0 tak jana hai (stop include nahi hota)
            # -1 = ulta chalna hai
            #
            # Example:
            # range(4,-1,-1)
            # => 4,3,2,1,0

            if arr[i] >= maxi:
                # agar current element right side ke
                # sabse bade element se bada ya equal hai
                # to ye leader hai

                ans.append(arr[i])

                maxi = arr[i]
                # naya maximum update

        return ans[::-1]
        # ans ab reverse order me hai
        # [2,5,17]
        # reverse karke
        # [17,5,2]