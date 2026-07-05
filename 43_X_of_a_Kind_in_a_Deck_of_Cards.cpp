class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
     unordered_map<int, int> counts;
     for(int card : deck){
        counts[card]++;
     }   
     int common_gcd = 0;
     for(auto const& [card, freq] : counts){
        if(common_gcd == 0){
            common_gcd = freq;
        }else{
            common_gcd = gcd(common_gcd, freq);
        }
     }
     return common_gcd >= 2;
    }
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a%b);
    }
};