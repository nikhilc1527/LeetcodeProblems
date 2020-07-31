class Solution:
    def twoSum(self, nums, target):
        a = {}
        for i, n in enumerate(nums):
            if n in a:
                return [i, a[n]]
            a[target - n] = i
        return None

print(*(Solution().twoSum({5, 1, 6}, 6)), sep=", ")
