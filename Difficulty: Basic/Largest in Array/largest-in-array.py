class Solution:
    def largest(self, arr):
        # code here
        maxi = float('-inf')
        for i in arr:
            if i>maxi:
                maxi = i
        return maxi
