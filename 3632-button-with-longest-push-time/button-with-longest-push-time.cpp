class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxi = events[0][1];
        int ans = events[0][0];

        for (int i = 1; i < events.size(); i++) {
            if (events[i][1] - events[i - 1][1] >= maxi) {
                if (maxi == events[i][1] - events[i - 1][1])
                    ans = min(ans, events[i][0]);
                else ans=events[i][0];
                maxi = events[i][1] - events[i - 1][1];
            }
        }
        return ans;
    }
};