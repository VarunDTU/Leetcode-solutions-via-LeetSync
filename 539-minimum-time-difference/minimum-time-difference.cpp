class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for (auto itr : timePoints) {
            times.push_back(60*(10*(itr[0]-'0')+(itr[1]-'0'))+(10*itr[3]-'0')+(itr[4]-'0'));
        }

        sort(times.begin(), times.end());
        int ans = INT_MAX;
        for (int i = 1; i < times.size(); i++) {
            cout<<times[i]<<endl;
            ans = min(ans, times[i] - times[i - 1]);
        }
        return min(ans, (60 * 24 + times[0]) - times.back());
    }
};