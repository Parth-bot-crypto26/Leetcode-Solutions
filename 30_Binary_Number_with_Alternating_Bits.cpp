class Solution {
public:
    bool hasAlternatingBits(int n) {
       bitset<32> a(n);
        int highest = 0;
        for(int i = 31; i >= 0; i--){
            if(a[i] == 1){
                highest = i;
                break;
            }
        }
        for(int i = 1; i <= highest; i++){
            if(a[i] == a[i-1]){
                return false;
            }
        }
        return true; 
    }
};