class Solution {
    vector<int>dp;
    int helper(int n){
        if(n<=1)return n;
        if(dp[n]!=-1)return dp[n];
        return helper(n-1)+helper(n-2);
    }
public:
    int fib(int n) {
        dp.resize(n+1,-1);
        return helper(n);
    }
};