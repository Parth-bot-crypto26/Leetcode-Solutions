class Solution {
public:
    struct Factors {
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
    };

    int getMinLength(Factors f) {
        int count = 0;
        count += f.c7;
        count += f.c5;
        int n9 = f.c3 / 2;
        f.c3 %= 2;
        int n8 = f.c2 / 3;
        f.c2 %= 3;
        
        if (f.c3 == 1 && f.c2 == 1) {
            count += 1;
            f.c3 = 0;
            f.c2 = 0;
        } else if (f.c3 == 1 && f.c2 == 2) {
            count += 1;
            count += 1;
            f.c3 = 0;
            f.c2 = 0;
        }
        
        if (f.c2 == 2) count += 1;
        else if (f.c2 == 1) count += 1;
        
        if (f.c3 == 1) count += 1;
        
        count += n9 + n8;
        return count;
    }

    bool canForm(Factors f, int len) {
        if (len < 0) return false;
        return getMinLength(f) <= len;
    }

    Factors reduceFactors(Factors f, int d) {
        if (d == 0) return f;
        while (d % 2 == 0 && f.c2 > 0) { f.c2--; d /= 2; }
        while (d % 3 == 0 && f.c3 > 0) { f.c3--; d /= 3; }
        if (d == 5 && f.c5 > 0) f.c5--;
        if (d == 7 && f.c7 > 0) f.c7--;
        return f;
    }

    string buildSmallestSuffix(Factors f, int len) {
        string res = "";
        for (int i = 0; i < len; ++i) {
            for (int d = 1; d <= 9; ++d) {
                Factors nextF = reduceFactors(f, d);
                if (canForm(nextF, len - 1 - i)) {
                    res += to_string(d);
                    f = nextF;
                    break;
                }
            }
        }
        return res;
    }

    string smallestNumber(string num, long long t) {
        Factors f;
        long long temp = t;
        while (temp % 2 == 0) { f.c2++; temp /= 2; }
        while (temp % 3 == 0) { f.c3++; temp /= 3; }
        while (temp % 5 == 0) { f.c5++; temp /= 5; }
        while (temp % 7 == 0) { f.c7++; temp /= 7; }
        
        if (temp > 1) return "-1";

        int n = num.length();
        int firstZero = num.find('0');
        if (firstZero == string::npos) firstZero = n;

        Factors currentF = f;
        for (char c : num) {
            currentF = reduceFactors(currentF, c - '0');
        }
        
        if (firstZero == n && currentF.c2 == 0 && currentF.c3 == 0 && currentF.c5 == 0 && currentF.c7 == 0) {
            return num;
        }

        vector<Factors> prefixF(n + 1);
        prefixF[0] = f;
        for (int i = 0; i < min(n, firstZero); ++i) {
            prefixF[i + 1] = reduceFactors(prefixF[i], num[i] - '0');
        }

        for (int i = min(n - 1, firstZero); i >= 0; --i) {
            int startDigit = (i < firstZero) ? (num[i] - '0' + 1) : 1;
            for (int d = startDigit; d <= 9; ++d) {
                Factors nextF = reduceFactors(prefixF[i], d);
                if (canForm(nextF, n - 1 - i)) {
                    string res = num.substr(0, i) + to_string(d);
                    res += buildSmallestSuffix(nextF, n - 1 - i);
                    return res;
                }
            }
        }
        int targetLen = max(n + 1, getMinLength(f));
        return buildSmallestSuffix(f, targetLen);
    }
};