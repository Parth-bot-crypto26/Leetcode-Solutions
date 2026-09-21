class Solution {
public:
    long long getGcd(long long a, long long b){
        while(b){
            a %= b;
            swap(a, b);
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd(n);
        int currentMax = 0;
        for(int i = 0; i < n; i++){
            currentMax = max(currentMax, nums[i]);
            prefixGcd[i] = getGcd(nums[i], currentMax);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long totalSum = 0;
        int left = 0;
        int right = n-1;
        while(left < right){
            totalSum += getGcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return totalSum;
    }
};