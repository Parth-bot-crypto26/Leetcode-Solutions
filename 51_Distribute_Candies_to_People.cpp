class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int i = 0;
        long long current_give = 1;
        while (candies > 0) {
            long long to_give = min((long long)candies, current_give);
            ans[i] += (int)to_give;
            candies -= (int)to_give;
            current_give++;
            i = (i + 1) % num_people;
        }
        return ans;
    }
};