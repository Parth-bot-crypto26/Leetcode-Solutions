class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)
        cost = [[0] * 26 for _ in range(26)]
        for a in range(26):
            for b in range(26):
                d = (a-b) % 26
                cost[a][b] = min(d, 26-d)
        idx = [ord(c) - 97 for c in s]
        best = float('inf')
        for r in range(n):
            total = r
            for i in range(n // 2):
                a = idx[(i+r) % n]
                b = idx[(n-1-i+r) % n]
                total += cost[a][b]
                if total >= best:
                    break
            best = min(best, total)
        return best