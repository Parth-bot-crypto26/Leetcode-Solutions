class Solution:
    def minPrice(self, prices: list[int], discounts: list[int]) -> float:
        prices = sorted(prices, reverse=True)
        discounts = sorted(discounts, reverse=True)
        n = len(prices)
        m = len(discounts)
        k = min(n, m)
        total = float(sum(prices))
        for i in range(k):
            total -= prices[i] * discounts[i] / 100.0
        return total