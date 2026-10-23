class Solution {
public:
    int smallestNumber(int n, int t) {
        int curr = n;
        while(true){
            int prod = 1;
            int temp = curr;
            while(temp > 0){
                prod *= (temp%10);
                temp /= 10;
            }
            if(prod % t == 0){
                return curr;
            }
            curr++;
        }
    }
};