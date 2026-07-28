class NumArray {
public:
    vector<int> pref;
    NumArray(vector<int>& nums) {
        pref.push_back(0);
        for(int num : nums){
            pref.push_back(pref.back()+num);
        }
    }
    
    int sumRange(int left, int right) {
        return pref[right+1]-pref[left];
    }
};