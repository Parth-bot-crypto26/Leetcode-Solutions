class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int totalCount = 0;
        for(int i = left; i <= right; ++i){
            int setBits = __builtin_popcount(i);
            if(isPrime(setBits)){
                totalCount++;
            }
        }
        return totalCount;
    }
private:
bool isPrime(int n){
    return (n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19);
}
};