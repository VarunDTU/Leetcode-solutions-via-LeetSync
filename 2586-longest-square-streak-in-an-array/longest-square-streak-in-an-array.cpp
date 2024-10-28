class Solution {
public:
    unordered_map<int, int> dp;
    int ans = -1;
  
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int itr = 0; itr < nums.size(); itr++) {
            int root = sqrt(nums[itr]);
            if (root * root == nums[itr]) {
                if (dp.find(root) == dp.end())
                    dp[nums[itr]] = 1;
                else
                    dp[nums[itr]] = 1 + dp[root];
                ans = max(dp[nums[itr]], ans);
            } else
                dp[nums[itr]] = 1;
        }
        return ans == 1 ? -1 : ans;
    }
};