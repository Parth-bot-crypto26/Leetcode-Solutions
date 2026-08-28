class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int target_count = 0;
            int total_count = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target) {
                    target_count++;
                }
                total_count++;
                if (target_count > total_count / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};