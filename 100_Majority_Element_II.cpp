class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counts;
        vector<int> ans;
        for(int num : nums){
            counts[num]++;
        }
        for(auto& pair : counts){
            if(pair.second > n/3){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};