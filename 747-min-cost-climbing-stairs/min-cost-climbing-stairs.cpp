class Solution {
    int helper(vector<int>&cost,vector<int>&dp,int index){
        if(index>=cost.size())return 0;
        if(dp[index]!=-1)return dp[index];
        return dp[index]= cost[index]+min(helper(cost,dp,index+1),helper(cost,dp,index+2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(helper(cost,dp,1),helper(cost,dp,0));
    }
};