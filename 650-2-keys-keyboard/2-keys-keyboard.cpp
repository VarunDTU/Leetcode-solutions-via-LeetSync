class Solution {
    int helper(int n,int l ,int i,vector<vector<int>>&dp){
        if(i>n)return 1e9;
        if(i==n)return 1;
        if(dp[i][l]!=-1)return dp[i][l];
        return dp[i][l]= min(2+helper(n,i,i+i,dp),1+helper(n,l,i+l,dp));
    }
public:
    int minSteps(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        if(n<=1)return 0;
        return helper(n,1,1,dp);
    }
};