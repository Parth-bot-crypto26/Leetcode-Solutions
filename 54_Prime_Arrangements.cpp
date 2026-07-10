class Solution {
public:
    int numPrimeArrangements(int n) {
        int primeCount = countPrimes(n);
        int nonPrimeCount = n - primeCount;
        long long MOD = 1e9 + 7;
        return (factorial(primeCount, MOD) * factorial(nonPrimeCount, MOD)) % MOD;
    }

private:
    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
    int countPrimes(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (isPrime(i)) count++;
        }
        return count;
    }
    long long factorial(int n, long long mod) {
        long long res = 1;
        for (int i = 2; i <= n; i++) {
            res = (res * i) % mod;
        }
        return res;
    }
};