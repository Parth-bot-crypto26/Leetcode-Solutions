class Solution:
    def sumDecoded(self, nums: list[int]) -> int:
        MOD = 10**9+7
        total = 0
        for num in nums:
            w = num % 10
            d = num // 10
            dStr = str(d)
            x = int(dStr[:w])
            y = int(dStr[w:])
            total = (total + pow(x, y, MOD)) % MOD
        return total