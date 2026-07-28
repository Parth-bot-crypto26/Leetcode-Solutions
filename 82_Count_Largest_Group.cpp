class Solution {
private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;       
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        int groupSizes[37] = {0};
        int maxSize = 0;
        for (int i = 1; i <= n; ++i) {
            int sum = getDigitSum(i);
            groupSizes[sum]++;
            if (groupSizes[sum] > maxSize) {
                maxSize = groupSizes[sum];
            }
        }
        int largestGroupCount = 0;
        for (int i = 1; i < 37; ++i) {
            if (groupSizes[i] == maxSize) {
                largestGroupCount++;
            }
        }
        return largestGroupCount;
    }
};