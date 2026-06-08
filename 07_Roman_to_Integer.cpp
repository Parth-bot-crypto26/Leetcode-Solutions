class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> grid;
        grid['I'] = 1;
        grid['V'] = 5;
        grid['X'] = 10;
        grid['L'] = 50;
        grid['C'] = 100;
        grid['D'] = 500;
        grid['M'] = 1000;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && grid[s[i]] < grid[s[i + 1]]) {
                count -= grid[s[i]];
            } else {
                count += grid[s[i]];
            }
        }
        return count;
    }
};