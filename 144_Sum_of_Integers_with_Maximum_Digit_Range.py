class Solution:
    def maxDigitRange(self, nums: list[int]) -> int:
        maxRange = -1
        sum = 0
        for num in nums:
            Strnum = str(abs(num))
            maxCh = max(Strnum)
            minCh = min(Strnum)
            dRange = int(maxCh)-int(minCh)
            if dRange > maxRange:
                maxRange = dRange
                sum = num
            elif dRange == maxRange:
                sum += num
        return sum