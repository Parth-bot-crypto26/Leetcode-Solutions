class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while(columnNumber > 0){
            columnNumber--;
            char curr = (columnNumber%26)+'A';
            result += curr;
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};