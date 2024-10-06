class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        queue<int>q;
        for(int k=0;k<n;k++){
            if(vis[k]!=-1)continue;
            vis[k]=true;
            q.push(k);

            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int i=0;i<graph[node].size();i++){
                    if(vis[graph[node][i]]==-1){q.push(graph[node][i]);vis[graph[node][i]]=!vis[node];}
                    else if(vis[graph[node][i]]==vis[node])return false;
                }
            }
        }
        return true;
    }
};