class Solution {
    int helper(int k,int n,vector<vector<int>>&dp){
        if(n==0||n==1)return n;
        if(k==1)return n;
        if(dp[k][n]!=-1)return dp[k][n];
        int s=1,mid,e=n,ans=INT_MAX;
        while(s<=e){
            mid=s+(e-s)/2;
            int a=helper(k-1,mid-1,dp);
            int b=helper(k,n-mid,dp);
            if(a>=b)e=mid-1;
            else s=mid+1;
             ans=min(ans,max(a,b));
        }
        return dp[k][n]=ans+1;
    }
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return helper(k,n,dp);
    }
};