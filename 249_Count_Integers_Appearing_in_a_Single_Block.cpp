class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_set<int> uniqueEl;
        unordered_set<int> seen;
        unordered_set<int> invalid;
        for(int i = 0; i < nums.size(); ++i){
            uniqueEl.insert(nums[i]);
            if(seen.count(nums[i])){
                invalid.insert(nums[i]);
            }
            if(i > 0 && nums[i] != nums[i-1]){
                seen.insert(nums[i-1]);
            }
        }
        return uniqueEl.size() - invalid.size();
    }
};