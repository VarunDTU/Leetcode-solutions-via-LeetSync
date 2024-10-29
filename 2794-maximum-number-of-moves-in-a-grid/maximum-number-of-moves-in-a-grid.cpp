class Solution {
    int dfs(vector<vector<int>>& grid,int i,int j,int prev){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||prev>=grid[i][j])return 0;
        int temp=grid[i][j];
        grid[i][j]=0;
        return 1+max({dfs(grid,i-1,j+1,temp),dfs(grid,i,j+1,temp),dfs(grid,i+1,j+1,temp)});
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            ans=max(ans,dfs(grid,i,0,-1));
        }
        return ans-1;
    }
};