class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeroDup = 0;
        int length = n - 1;

        for (int i = 0; i <= length; i++) {
            if (arr[i] == 0) {
                if (i == length) {
                    arr[n - 1] = 0;
                    n--;
                    length--; 
                    break;
                }
                zeroDup++;
                length--;
            }
        }

        int lastIdx = length;
        for (int i = lastIdx; i >= 0; i--) {
            if (arr[i] == 0) {
                arr[i + zeroDup] = 0;
                zeroDup--;
                arr[i + zeroDup] = 0;
            } else {
                arr[i + zeroDup] = arr[i];
            }
        }
    }
};