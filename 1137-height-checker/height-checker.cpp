class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> h(heights.begin(), heights.end());
        sort(h.begin(), h.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
            if (heights[i] != h[i])
                ans++;
        return ans;
    }
};