class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int row=0,c1=0;
        while(row<grid.size()){
            int s=0,e=grid[0].size()-1;
            while(s<=e){
                if(grid[row][s]!=grid[row][e])c1++;
                s++;
                e--;
            }
            row++;
        }
        int c2=0,col=0;
        while(col<grid[0].size()){
            int s=0,e=grid.size()-1;
            while(s<=e){
                if(grid[s][col]!=grid[e][col])c2++;
                s++;
                e--;
            }
            col++;
        }
        return min(c1,c2);
    }
};