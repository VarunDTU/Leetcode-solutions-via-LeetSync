class Solution {
public:
    long long minNumberOfSeconds(int height, vector<int>& w) {
        priority_queue<pair<long long, pair<long long, long long>>,
                       vector<pair<long long, pair<long long, long long>>>,
                       greater<pair<long long, pair<long long, long long>>>>
            q;
        for (int i = 0; i < w.size(); i++) {
            q.push({w[i], {1, w[i]}});
        }
        int ans = 1;
        while (height > 0) {
            long long oldcost = q.top().first;
            long long h = q.top().second.first;
            long long  work = q.top().second.second;
            height--;
            if (height == 0)
                return (long long)oldcost;
            q.pop();
           
            q.push({{(long long)work * (h + 1) * (h + 2) / 2}, {h + 1, work}});
        }

        return ans * (ans + 1) / 2;
    }
};