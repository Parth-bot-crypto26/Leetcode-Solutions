class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        int n1 = series1.size(), n2 = series2.size();
        while(i < n1 || j < n2){
            int t;
            if(i < n1 && j < n2){
                t = min(series1[i][0], series2[j][0]);
            }else if(i < n1){
                t = series1[i][0];
            }else{
                t = series2[j][0];
            }
            if(i < n1 && series1[i][0] < t) i++;
            if(j < n2 && series2[j][0] < t) j++;
            int val1 = (i < n1) ? series1[i][1] : 0;
            int val2 = (j < n2) ? series2[j][1] : 0;
            ans.push_back({t, val1+val2});
            if(i < n1 && series1[i][0] == t) i++;
            if(j < n2 && series2[j][0] == t) j++;
        }
        return ans;
    }
};