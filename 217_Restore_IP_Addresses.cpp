class Solution {
    bool isValid(const string& s){
        if(s.empty() || s.length() > 3) return false;
        if(s.length() > 1 && s[0] == '0') return false;
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int n = s.length();
        if(n < 4 || n > 12) return result;
        for(int l1 = 1; l1 <= 3 && l1 < n; ++l1){
            for(int l2 = 1; l2 <= 3 && l1+l2 < n; ++l2){
                for(int l3 = 1; l3 <= 3 && l1+l2+l3 < n; ++l3){
                    int l4 = n-(l1+l2+l3);
                    if(l4 >= 1 && l4 <= 3){
                        string s1 = s.substr(0, l1);
                        string s2 = s.substr(l1, l2);
                        string s3 = s.substr(l1+l2, l3);
                        string s4 = s.substr(l1+l2+l3, l4);
                        if(isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)){
                            result.push_back(s1+'.'+s2+'.'+s3+'.'+s4);
                        }
                    }
                }
            }
        }
        return result;
    }
};