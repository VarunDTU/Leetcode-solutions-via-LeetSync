class Solution {
public:
    vector<vector<int>> dp;
    bool helper(vector<int>& nums, int sum, int i) {
        if (!sum)
            return true;
        if (i == nums.size() || sum < 0)
            return false;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        return dp[i][sum] = helper(nums, sum - nums[i], i + 1) ||
                            helper(nums, sum, i + 1);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;
        dp.resize(nums.size() + 1, vector<int>(sum + 1, -1));
        sum /= 2;
        return helper(nums, sum, 0);
    }
};