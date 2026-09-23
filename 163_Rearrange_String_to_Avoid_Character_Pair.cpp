class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string yChars = "";
        string xChars = "";
        string others = "";
        for(char c : s){
            if(c == y){
                yChars += c;
            }else if(c == x){
                xChars += c;
            }else{
                others += c;
            }
        }
        return yChars+others+xChars;
    }
};