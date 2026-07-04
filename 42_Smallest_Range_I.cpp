class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_val = nums[0];
        int max_val = nums[0];
        for(int x : nums){
            if(x < min_val) min_val = x;
            if(x > max_val) max_val = x;
        }
        int diff = (max_val-k)-(min_val+k);
        return max(0, diff);
    }
};