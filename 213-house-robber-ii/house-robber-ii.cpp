class Solution {
    int helper(vector<int>&nums,int i,int n, vector<int>&dp){
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]= max(helper(nums,i+1,n,dp),nums[i]+helper(nums,i+2,n,dp));
    }
public:
    int rob(vector<int>& nums) {

        if(nums.size()==1)return nums.back();
        if(nums.size()==2)return max(nums[0],nums[1]);
        vector<int>dp(nums.size()+1,-1);

        int x=helper(nums,1,nums.size()-1,dp);
        fill(dp.begin(),dp.end(),-1);
        return max(helper(nums,0,nums.size()-2,dp),x);
    }
};