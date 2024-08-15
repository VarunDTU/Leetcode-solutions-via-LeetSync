class Solution {
public:
    int helper(vector<int>&nums,vector<vector<int>>&dp,int i,int j){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MIN;
        for(int k=i;k<=j;k++)mini=max(mini,nums[i-1]*nums[j+1]*nums[k]+helper(nums,dp,i,k-1)+helper(nums,dp,k+1,j));
        return dp[i][j]=mini;
    }   
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return helper(nums,dp,1,nums.size()-2);
    }
};