class Solution {
    int LIS(vector<int>&nums,int i,int prev,vector<int>&dp){
        if(i==nums.size())return 0;
        if(dp[prev+1]!=-1)return dp[prev+1];
        if(prev==-1||nums[i]>nums[prev])return dp[prev+1]= max(1+LIS(nums,i+1,i,dp),LIS(nums,i+1,prev,dp));
        return dp[prev+1]= LIS(nums,i+1,prev,dp);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return LIS(nums,0,-1,dp);
    }
};