class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<bool> rowOdd(m, false);
        vector<bool> colOdd(n, false);
        for (const auto& index : indices) {
            rowOdd[index[0]] = !rowOdd[index[0]];
            colOdd[index[1]] = !colOdd[index[1]];
        }
        int oddRows = 0;
        for (bool r : rowOdd) {
            if (r) oddRows++;
        }
        int oddCols = 0;
        for (bool c : colOdd) {
            if (c) oddCols++;
        }
        return oddRows * (n - oddCols) + oddCols * (m - oddRows);
    }
};