class Solution {
    //nums.size()* target;
    vector<vector<int>>dp;
    int helper(vector<int>& nums, int target,int idx){
        if(target==0)return 1;
        if(target<0)return 0;
        if(idx==nums.size())return 0;
        if(dp[idx][target]!=-1)return dp[idx][target];
        if(target>=nums[idx])return dp[idx][target]= helper(nums,target-nums[idx],0)+helper(nums,target,idx+1);
        return dp[idx][target]= helper(nums,target,idx+1);
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(nums.size(),vector<int>(target+1,-1));
        return helper(nums,target,0);
    }
};