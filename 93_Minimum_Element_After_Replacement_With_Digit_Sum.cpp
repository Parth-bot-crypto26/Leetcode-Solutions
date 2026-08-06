class Solution {
public:
    int getDigitSum(int n){
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int min_sum = INT_MAX;
        for(int num : nums){
            int current = getDigitSum(num);
            if(current < min_sum){
                min_sum = current;
            }
        }
        return min_sum;
    }
};