class Solution {
    vector<int> parent, edgeCount, nodeCount;
    int findParent(int i) {
        if (parent[i] == -1)
            return i;
        return findParent(parent[i]);
    }
    void setParent(int i, int j) {
        int iParent = findParent(i);
        int jParent = findParent(j);
        edgeCount[iParent]++;
        if (iParent != jParent) {
            parent[jParent] = iParent;
            edgeCount[iParent] += edgeCount[jParent];
            nodeCount[iParent] += nodeCount[jParent];
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n, -1);
        edgeCount.resize(n, 0);
        nodeCount.resize(n, 1);
        for (auto itr : edges)
            setParent(itr[0], itr[1]);
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (nodeCount[i]!=0&&parent[i] == -1 &&
                edgeCount[i] == ((nodeCount[i] * (nodeCount[i] - 1)) / 2))
                ans++;
        return ans;
    }
};