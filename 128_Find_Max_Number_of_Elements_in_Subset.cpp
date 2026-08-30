class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for (int x : nums) {
            counts[x]++;
        }
        int max_len = 1;
        if (counts.count(1)) {
            int ones = counts[1];
            if (ones % 2 == 0) {
                max_len = max(max_len, ones - 1);
            } else {
                max_len = max(max_len, ones);
            }
        }
        for (auto& [val, count] : counts) {
            if (val == 1) continue;
            long long current = val;
            int current_len = 0;
            while (counts.count(current) && counts[current] >= 2) {
                current_len += 2;
                current = current * current;
            }  
            if (counts.count(current) && counts[current] >= 1) {
                current_len += 1;
            } else {
                current_len -= 1;
            }     
            max_len = max(max_len, current_len);
        }
        return max_len;
    }
};