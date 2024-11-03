class Solution {
    set<int> d;
    void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int i) {
        vis[i] = true;
        d.insert(i);
        for (auto itr : rooms[i])
            if (!vis[itr])
                dfs(rooms, vis, itr);
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        dfs(rooms, vis, 0);
        return d.size() == rooms.size();
    }
};