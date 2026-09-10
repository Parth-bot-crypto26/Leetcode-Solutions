class Solution:
    def maxValidPairSum(self, nums: list[int], k: int) -> int:
        n = len(nums)
        maxSum = float('-inf')
        maxPref = float('-inf')
        for j in range(k, n):
            maxPref = max(maxPref, nums[j-k])
            currentSum = maxPref + nums[j];
            maxSum = max(maxSum, currentSum)
        return maxSum