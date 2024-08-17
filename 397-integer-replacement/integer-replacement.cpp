class Solution {
public:
    int helper(int n,map<int,int>&dp){
        if(n==1)return 0;
        if(dp.find(n)!=dp.end())return dp[n];
        if(n%2==0)return dp[n]=1+helper(n/2,dp);
        return  dp[n]=2+min(helper(n/2+1,dp),helper(n/2,dp));
    }
    int integerReplacement(int n) {
        map<int,int>dp;
        return helper(n,dp);
    }
};