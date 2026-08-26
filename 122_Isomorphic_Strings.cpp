class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;
        for(int i = 0; i < s.length(); i++){
            char charS = s[i];
            char charT = t[i];
            int lastPosS = mapS.count(charS) ? mapS[charS] : -1;
            int lastPosT = mapT.count(charT) ? mapT[charT] : -1;
            if(lastPosS != lastPosT){
                return false;
            }
            mapS[charS] = i;
            mapT[charT] = i;
        }
        return true;

    }
};