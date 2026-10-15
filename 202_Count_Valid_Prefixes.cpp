class Solution {
public:
    int countValidPrefixes(string s) {
        int cnt0 = 0, cnt1 = 0, ans = 0;
        for(char c : s){
            if(c == '0'){
                cnt0++;
            }else{
                cnt1++;
            }
            if(abs(cnt0-cnt1) <= 1){
                ans++;
            }
        }
        return ans;
    }
};