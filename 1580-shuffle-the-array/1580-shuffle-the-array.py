class Solution(object):
    def shuffle(self, nums, n):
        l = []
        for i in range(n):
            l.append(nums[i])
            l.append(nums[i + n])
        return l
        