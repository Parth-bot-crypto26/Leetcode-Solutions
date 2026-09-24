class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        long long p = n/2;
        long long upVal = (long long)s+m+(p-1)*(long long)(m-1);
        long long q = (n+1)/2;
        long long downVal = (long long)s+(q-1)*(long long)(m-1);
        return max(upVal, downVal);
    }
};