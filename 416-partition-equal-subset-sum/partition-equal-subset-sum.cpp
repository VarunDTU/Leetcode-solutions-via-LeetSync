class Solution {
    bool helper(vector<int>& nums, vector<vector<int>>& dp, int &sum, int i,
                int c) {
        if (c == sum) {
            return true;
        }
        if (i == nums.size() || c > sum)
            return false;

        if (dp[i][c] != -1)
            return dp[i][c];
        return dp[i][c] = (helper(nums, dp, sum, i + 1, c + nums[i]) ||
                             helper(nums, dp, sum, i + 1, c));
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
        return helper(nums, dp, sum, 0, 0);
    }
};