class Solution {
    long long helper(vector<vector<int>>& q, vector<long long>&dp,int index){
        if(index>=q.size())return 0;
        if(dp[index]!=-1)return dp[index];
        vector<int> cost= q[index];
        int i=index;
        long long notPick=helper(q,dp,index+1);
        index+=cost[1]+1;
        return dp[i]= (long long)max(helper(q,dp,index)+cost[0],notPick);
    }
public:
    long long mostPoints(vector<vector<int>>& q) {
        vector<long long>dp(q.size()+1,-1);
        return helper(q,dp,0);
    }
};