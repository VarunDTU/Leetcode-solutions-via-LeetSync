class Solution {
public:
    int dp[101][101];
    int helper(vector<int>&cuts,int start,int end,int startcut,int endcut){
        if(start>end)return 0;
        int ans=INT_MAX;
        if(dp[start][end]!=-1)return dp[start][end];
        for(int i=start;i<=end;i++){
            int leftcut=helper(cuts,start,i-1,startcut,cuts[i]);
            int rightcut=helper(cuts,i+1,end,cuts[i],endcut);
            int cost=(endcut-startcut)+leftcut+rightcut;
            ans=min(ans,cost);
        }
        return dp[start][end]=ans;
        
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        sort(cuts.begin(),cuts.end());
        return helper(cuts,0,cuts.size()-1,0,n);
    }
};