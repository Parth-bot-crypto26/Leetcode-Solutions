class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < n; ++i) {
            indices[nums[i]].push_back(i);
        }

        long long min_dist = -1;

        for (auto const& [val, pos] : indices) {
            if (pos.size() < 3) continue;

            for (int i = 0; i <= (int)pos.size() - 3; ++i) {
                int first = pos[i];
                int third = pos[i + 2];
                long long current_dist = 2LL * (third - first);
                
                if (min_dist == -1 || current_dist < min_dist) {
                    min_dist = current_dist;
                }
            }
        }

        return (int)min_dist;
    }
};