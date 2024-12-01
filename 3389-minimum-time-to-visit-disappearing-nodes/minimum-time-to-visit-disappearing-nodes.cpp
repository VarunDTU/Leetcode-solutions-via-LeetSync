class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges,
                            vector<int>& disappear) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        vector<vector<pair<int, int>>> adj(n);
        for (auto itr : edges) {
            adj[itr[0]].push_back({itr[1], itr[2]});
            adj[itr[1]].push_back({itr[0], itr[2]});
        }
        vector<int> ans(n, -1);
        q.push({0, 0});
        while (!q.empty()) {

            int curr = q.top().second;
            int currCost = q.top().first;
            cout << curr << currCost << endl;
            q.pop();
            if (ans[curr] != -1)
                continue;

            ans[curr] = currCost;

            for (auto itr : adj[curr]) {
                if (ans[itr.first] == -1 &&
                    currCost + itr.second < disappear[itr.first]) {
                    q.push({itr.second + currCost, itr.first});
                }
            }
        }
        return ans;
    }
};