class Solution {
    int helper(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size())
            return 0;

        if(dp[index]!=-1)return dp[index];
        int i=index;
        int curr_point = nums[index];
        int curr_sum = 0;
        while (index < nums.size() && curr_point == nums[index]) {
            curr_sum += nums[index];
            index++;
        }
        int notPick=helper(nums,index,dp);

        while (index < nums.size() && (curr_point+1) == nums[index]) {
            index++;
        }
        int pick =helper(nums,index,dp)+curr_sum;
        return dp[i]=max(pick,notPick);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size()+1,-1);
        return helper(nums,0,dp);
    }
};