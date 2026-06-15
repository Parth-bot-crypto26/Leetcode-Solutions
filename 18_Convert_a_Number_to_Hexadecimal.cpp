class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        unsigned int n = num;
        string hex_map = "0123456789abcdef";
        string result = "";
        while(n != 0){
            int last_4_bits = n&15;
            result += hex_map[last_4_bits];
            n = n >> 4;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};