class Solution {

    int helper(vector<vector<int>>& matrix, int i, int j,vector<vector<int>>& t) {
        if (i == matrix.size() || j == matrix[0].size()||matrix[i][j] == 0)
            return 0;
            if(t[i][j]!=-1)return t[i][j];
    
            return t[i][j]= 1 + min({helper(matrix, i + 1, j + 1,t),
                                   helper(matrix, i + 1, j,t),
                                   helper(matrix, i, j + 1,t)});
    
    }

public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
      int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
              if(matrix[i][j]==1)ans+=helper(matrix,i,j,dp);
            }
        }
        return ans;
    }
};