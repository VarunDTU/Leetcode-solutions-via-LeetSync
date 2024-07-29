class Solution {
public:
    
    int helper(vector<int>&nums,int i,bool mustpick,vector<vector<int>>&dp){
        if(i==nums.size())return mustpick?0:-1e9;
        if(dp[i][mustpick]!=-1e9)return dp[i][mustpick];
        if(mustpick)return dp[i][mustpick]= max(0,nums[i]+helper(nums,i+1,true,dp));
        return dp[i][mustpick]=max(helper(nums,i+1,false,dp),nums[i]+helper(nums,i+1,true,dp));
    }
    int maxSubArray(vector<int>& nums) {
         ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>>dp(nums.size()+1,vector<int>(2,-1e9));
        return helper(nums,0,false,dp);
    }
};