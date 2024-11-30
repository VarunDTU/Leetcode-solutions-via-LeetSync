class Solution {
    int bfs(int n,vector<vector<int>>&adj){
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>vis(n,false);
        while(!q.empty()){
            int node=q.front().first;
            vis[node]=true;
            int cost=q.front().second;
            q.pop();
            if(node==n-1)return cost;
            for(auto itr:adj[node]){
                if(!vis[itr])
                q.push({itr,cost+1});
            }
        }
        return -1;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }

        vector<int>ans;
        for(auto itr:queries){
            adj[itr[0]].push_back(itr[1]);
            ans.push_back(bfs(n,adj));
        }
        return ans;


    }
};