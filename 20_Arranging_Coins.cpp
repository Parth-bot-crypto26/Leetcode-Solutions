class Solution {
public:
    int arrangeCoins(int n) {
     long left = 0;
        long right = n;
        while (left <= right) {
            long k = left + (right - left) / 2;
            long curr_coins = k * (k + 1) / 2;
            if (curr_coins == n) {
                return (int)k;
            }
            if (curr_coins < n) {
                left = k + 1;
            } else {
                right = k - 1;
            }
        }
        return (int)right;
    }
};