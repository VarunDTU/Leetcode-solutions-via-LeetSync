class Solution {
public:
    vector<vector<int>> dp;
    bool helper(vector<int>& nums, int &sum, int curr_sum, int i) {
        if (curr_sum == sum)
            return true;
        if (i == nums.size() || curr_sum > sum)
            return false;
        if (dp[i][curr_sum] != -1)
            return dp[i][curr_sum];
        return dp[i][curr_sum] = helper(nums, sum, curr_sum + nums[i], i + 1) ||
                                 helper(nums, sum, curr_sum, i + 1);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        dp.resize(nums.size() + 1, vector<int>(sum + 1, -1));
        sum /= 2;
        return helper(nums, sum, 0, 0);
    }
};