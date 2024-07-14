class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        priority_queue<pair<int, char>> q;
        for (auto itr : hc)
            q.push({itr, 'h'});
        for (auto itr : vc)
            q.push({itr, 'v'});
        int cuth = 1, cutv = 1, ans = 0;
        while (!q.empty()) {
            int cost = q.top().first;
            int cut = q.top().second;
            q.pop();
            if (cut == 'h') {
                ans += cutv * cost;
                cuth++;
            } else {
                ans += cuth * cost;
                cutv++;
            }
        }
        return ans;
    }
};