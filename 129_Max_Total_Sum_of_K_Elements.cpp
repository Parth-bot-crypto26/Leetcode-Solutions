class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());
        long long total = 0;
        for(int i = 0; i < k; ++i){
            long long currentMul = max(1, mul-i);
            total += (long long)nums[i] * currentMul;
        }
        return total;
    }
};