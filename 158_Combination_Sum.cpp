class Solution {
public:
    set<vector<int>> s;
    void getAllComb(vector<int>& nums, int idx, int target, vector<vector<int>>& ans, vector<int>& combination){
        if(idx == nums.size() || target < 0){
            return;
        }
        if(target == 0){
            if(s.find(combination) == s.end()){
                ans.push_back({combination});
                s.insert(combination);
            }
            return;
        }
        combination.push_back(nums[idx]);
        getAllComb(nums, idx+1, target-nums[idx], ans, combination);
        getAllComb(nums, idx, target-nums[idx], ans, combination);
        combination.pop_back();
        getAllComb(nums, idx+1, target, ans, combination);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        getAllComb(nums, 0, target, ans, combination);
        return ans;
    }
};