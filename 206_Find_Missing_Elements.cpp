class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        int minVal = nums[0], maxVal = nums[n-1];
        int idx = 0;
        for(int count = minVal; count <= maxVal; count++){
            if(idx < n && nums[idx] == count){
                while(idx < n && nums[idx] == count){
                    idx++;
                }
            }else{
                ans.push_back(count);
            }
        }
        return ans;
    }
};