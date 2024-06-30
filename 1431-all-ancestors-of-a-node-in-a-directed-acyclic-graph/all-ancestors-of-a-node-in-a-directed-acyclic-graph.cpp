class Solution {
public:
    void dfs(int i, int &j, vector<vector<int>>& ed, vector<vector<int>>& ans,
             vector<bool>& vis) {
        vis[i] = true;
        for (int itr : ed[i]) {
            if (!vis[itr]) {
                ans[itr].push_back(j);
                dfs(itr, j, ed, ans, vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ed(n);
        vector<vector<int>> ans(n);
        for (auto itr : edges) {
            ed[itr[0]].push_back(itr[1]);
        }
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            dfs(i, i, ed, ans, vis);
        }
        return ans;
    }
};