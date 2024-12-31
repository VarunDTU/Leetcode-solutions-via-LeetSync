class Solution {
    int helper(vector<int>&days,vector<int>&costs,int index,vector<int>&dp){

        if(index>=days.size())return 0;
        if(dp[index]!=-1)return dp[index];
        int c1=helper(days,costs,index+1,dp)+costs[0];
        int i;
        for( i=index;i<days.size()&&days[i]<days[index]+7;i++);
        int c2=helper(days,costs,i,dp)+costs[1];
        for( i=index;i<days.size()&&days[i]<days[index]+30;i++);
        int c3=helper(days,costs,i,dp)+costs[2];
        return dp[index]=min(c1,min(c2,c3));
            
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return helper(days,costs,0,dp);
    }
};