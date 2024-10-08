class Solution {
    long long helper(vector<vector<int>>& q, vector<long long>&dp,int index){
        if(index>=q.size())return 0;
        if(dp[index]!=-1)return dp[index];
        vector<int> cost= q[index];
        int i=index;
        index+=cost[1]+1;
        return dp[i]= (long long)max(helper(q,dp,index)+(long long)cost[0],helper(q,dp,i+1));
    }
public:
    long long mostPoints(vector<vector<int>>& q) {
        vector<long long>dp(q.size()+1,-1);
        return helper(q,dp,0);
    }
};