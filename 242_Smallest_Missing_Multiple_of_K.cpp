class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = k;
        while(true){
            if(!binary_search(nums.begin(), nums.end(), ans)){
                return ans;
            }
            ans += k;
        }
    }
};