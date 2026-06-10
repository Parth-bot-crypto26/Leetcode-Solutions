class Solution {
public:
    int titleToNumber(string columnTitle) {
        map<char, int> charValues;
        int val = 1;
        for(char c = 'A'; c <= 'Z'; c++){
            charValues[c] = val;
            val++;
        }
        long long result = 0;
        for(char c : columnTitle){
            result *= 26;
            result += charValues[c];
        }
        return result;
    }
};