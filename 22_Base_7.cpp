class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        bool negative = num < 0;
        num = abs(num);
        string result = "";
        while(num > 0){
            int digit = num % 7;
            result += to_string(digit);
            num /= 7;
        }
        if(negative){
            result += "-";
        }
        reverse(result.begin(), result.end());
        return result;
    }
};