class Solution:
    def minimumCost(self, nums: list[int], k: int) -> int:
        MOD = 10**9 + 7
        r = k
        ops = 0
        for num in nums:
            if r < num:
                needed = num - r
                m = (needed+k-1) // k
                r += m*k
                ops += m
            r -= num
        totalCost = ops * (ops+1) // 2
        return totalCost % MOD
    