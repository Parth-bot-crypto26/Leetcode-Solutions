class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int midVal = nums[n/2];
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == midVal) cnt++;
        }
        return cnt == 1;
    }
};