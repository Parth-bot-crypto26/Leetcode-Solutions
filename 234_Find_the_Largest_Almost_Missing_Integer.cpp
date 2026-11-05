class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) {
            int max_val = -1;
            for (int x : nums) {
                max_val = max(max_val, x);
            }
            return max_val;
        }
        if (k == 1) {
            unordered_map<int, int> count;
            for (int x : nums) {
                count[x]++;
            }
            int max_val = -1;
            for (auto& pair : count) {
                if (pair.second == 1) {
                    max_val = max(max_val, pair.first);
                }
            }
            return max_val;
        }
        unordered_map<int, int> count;
        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> unique_in_window;
            for (int j = 0; j < k; ++j) {
                unique_in_window.insert(nums[i + j]);
            }
            for (int x : unique_in_window) {
                count[x]++;
            }
        }
        int ans = -1;
        if (count[nums[0]] == 1) ans = max(ans, nums[0]);
        if (count[nums[n - 1]] == 1) ans = max(ans, nums[n - 1]);
        return ans;
    }
};