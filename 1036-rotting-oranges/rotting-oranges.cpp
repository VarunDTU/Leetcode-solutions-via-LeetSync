class Solution {
public:
    int dir[5]={-1,0,1,0,-1};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,i,j});
                }else if(grid[i][j]==1)count++;
            }
        }
        int ans=0;
        while(!q.empty()){
            int i=q.front()[1];
            int j=q.front()[2];
            int time=q.front()[0];
            q.pop();
            ans=max(ans,time);
            for(int k=0;k<4;k++){
                int row=i+dir[k];
                int col=j+dir[k+1];
                if(row>=0&&row<n&&col>=0&&col<m&&grid[row][col]==1){
                    grid[row][col]=2;
                    q.push({time+1,row,col});
                    count--;
                }
                
            }
        }
        return count==0?ans:-1;
        
        
    }
};