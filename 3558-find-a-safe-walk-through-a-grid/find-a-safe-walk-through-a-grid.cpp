class Solution {
    const int dic[5] = {-1, 0, 1, 0, -1};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>>
            q;
        vector<vector<bool>> vis(grid.size(),
                                 vector<bool>(grid[0].size(), false));
        if (grid[0][0] == 0)
            q.push({health, {0, 0}});
        else
            q.push({health - 1, {0, 0}});
        vis[0][0] = true;
        int n=grid.size(),m=grid[0].size();
        while (!q.empty()) {
            int x = q.top().second.first;
            int y = q.top().second.second;
            int c = q.top().first;
            if (x == n-1 && y==m-1) {
                if (c >= 1)
                    return true;
            }
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int i = x + dic[k], j = y + dic[k + 1];
                if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
                    !vis[i][j]) {
                    if (grid[i][j] == 0){
                        q.push({c, {i, j}});
                        vis[i][j] = true;
                    }
                    else{vis[i][j] = true;
                        q.push({c - 1, {i, j}});}
                }
            }
        }
        return false;
    }
};