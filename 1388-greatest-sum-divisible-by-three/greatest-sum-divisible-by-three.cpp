class Solution {
    int helper(vector<int>& nums, int i, int reminder,
               vector<vector<int>>& dp) {
        if (i == nums.size())
            return reminder == 0 ? 0 : -1e9;
        if (dp[i][reminder] != -1)
            return dp[i][reminder];
        return dp[i][reminder] = max(
                   nums[i] + helper(nums, i + 1, (reminder + nums[i]) % 3, dp),
                   helper(nums, i + 1, reminder, dp));
    }

public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(3, -1));
        return helper(nums, 0, 0, dp);
    }
};