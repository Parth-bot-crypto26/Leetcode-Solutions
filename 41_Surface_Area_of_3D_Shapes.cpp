class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int v = grid[i][j];
                if(v > 0){
                    total += 2;
                    int north = (i > 0) ? grid[i-1][j] : 0;
                    total += max(0, v-north);
                    int south = (i < n-1) ? grid[i+1][j] : 0;
                    total += max(0, v-south);
                    int west = (j > 0) ? grid[i][j-1] : 0;
                    total += max(0, v-west);
                    int east = (j < n-1) ? grid[i][j+1] : 0;
                    total += max(0, v-east);
                }
            }
        }
        return total;
    }
};