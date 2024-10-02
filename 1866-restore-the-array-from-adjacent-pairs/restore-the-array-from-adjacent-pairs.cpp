class Solution {
    void helper(unordered_map<int,vector<int>>&adj,int first,vector<int>&ans,unordered_set<int>&vis){
        if(ans.size()==adj.size())return;
        if(vis.find(first)==vis.end()){
            vis.insert(first);
            ans.push_back(first);
            helper(adj,adj[first][0],ans,vis);
           if(adj[first].size()>1)helper(adj,adj[first][1],ans,vis);
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>adj;
        for(auto itr:pairs){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        int first;
        for(auto itr:adj){
            if(itr.second.size()==1){
                first=itr.first;
            }
        }
        vector<int>ans;
        unordered_set<int>vis;
        helper(adj,first,ans,vis);
        return ans;


    }
};