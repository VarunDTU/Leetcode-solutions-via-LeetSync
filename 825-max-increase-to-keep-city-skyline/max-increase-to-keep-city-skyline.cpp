class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int>row(grid.size(),0),col(grid.size(),0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                row[i]=max(row[i],grid[i][j]);
                col[i]=max(col[i],grid[j][i]);
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                ans+=min(col[j],row[i])-grid[i][j];
            }
        }
        return ans;

    }
};