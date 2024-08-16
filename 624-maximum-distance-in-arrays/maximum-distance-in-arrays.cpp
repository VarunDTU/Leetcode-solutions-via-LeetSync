class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int biggest = arrays[0].back(), smallest = arrays[0][0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max({ans, abs(arrays[i].back() - smallest),
                           abs(arrays[i][0] - biggest)});
            smallest=min(smallest,arrays[i][0]);
            biggest=max(biggest,arrays[i].back());
        }
        return ans;
    }
};