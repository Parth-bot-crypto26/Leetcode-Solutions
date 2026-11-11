class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for(char c : s) count[c-'a']++;
        for(int i = n-1; i >= 0; --i){
            vector<int> tempCnt = count;
            bool possible = true;
            string prefix = "";
            for(int j = 0; j < i; ++j){
                int idx = target[j] - 'a';
                if(tempCnt[idx] > 0){
                    tempCnt[idx]--;
                    prefix += target[j];
                }else{
                    possible = false;
                    break;
                }
            }
            if(!possible) continue;
            char nextChar = ' ';
            for(int c = target[i]-'a'+1; c < 26; ++c){
                if(tempCnt[c] > 0){
                    nextChar = 'a'+c;
                    break;
                }
            }
            if(nextChar != ' '){
                tempCnt[nextChar-'a']--;
                prefix += nextChar;
                string suffix = "";
                for(int c = 0; c < 26; ++c){
                    suffix.append(tempCnt[c], 'a'+c);
                }
                return prefix+suffix;
            }
        }
        return "";
    }
};