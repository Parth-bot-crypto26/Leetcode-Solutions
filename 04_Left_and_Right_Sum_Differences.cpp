class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> ans(n, 0);
        int currLeftSum = 0;
        for(int i = 0; i < n; i++){
            left[i] = currLeftSum;
            currLeftSum += nums[i];
        }
        int currRightSum = 0;
        for(int i = n-1; i >= 0; i--){
            right[i] = currRightSum;
            currRightSum += nums[i];
        }
        for(int i = 0; i < n; i++){
            ans[i] = abs(left[i]-right[i]);
        }
        return ans;
    }
};