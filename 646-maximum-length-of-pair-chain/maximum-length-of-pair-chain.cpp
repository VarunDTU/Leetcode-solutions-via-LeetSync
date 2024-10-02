class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int ans = 0, curr = INT_MIN;
        for (auto& itr : pairs) {
            if (itr[0] > curr) {
                curr = itr[1];
                ans++;
            }
        }
        return ans;
    }
};