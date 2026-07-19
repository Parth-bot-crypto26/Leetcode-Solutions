class Solution {
public:
    int maximum69Number (int num) {
        std::string numStr = std::to_string(num);
        for (int i = 0; i < numStr.length(); i++) {
            if (numStr[i] == '6') {
                numStr[i] = '9';
                break;          
            }
        }
        return std::stoi(numStr);
    }
};