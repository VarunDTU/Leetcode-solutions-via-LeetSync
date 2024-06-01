class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != -1)
            return find(parent[x], parent);
        return x;
    }
    vector<int> Union(int x, int y, vector<int>& parent) {
        int xset = find(x, parent);
        int yset = find(y, parent);
        if (xset == yset)
            return {x, y};
        parent[yset] = xset;
        return {-1};
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1,-1);
        vector<int> ans;
        for (auto itr : edges) {
            vector<int> temp = Union(itr[0], itr[1], parent);
            if (temp.size() > 1)
                ans = temp;
        }
        return ans;
    }
};