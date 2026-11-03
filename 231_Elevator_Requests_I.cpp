class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int timeTaken = 0;
        int currFloor = 0;
        for(int req : requests){
            timeTaken += abs(req-currFloor);
            currFloor = req;
        }
        return timeTaken;
    }
};