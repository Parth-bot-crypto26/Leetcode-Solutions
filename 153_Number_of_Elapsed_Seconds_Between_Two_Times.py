class Solution:
    def secondsBetweenTimes(self, startTime: str, endTime: str) -> int:
        startSec = int(startTime[0:2])*3600 + int(startTime[3:5])*60 + int(startTime[6:8])
        endSec = int(endTime[0:2])*3600 + int(endTime[3:5])*60 + int(endTime[6:8])
        return endSec-startSec