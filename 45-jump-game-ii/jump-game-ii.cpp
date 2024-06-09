class Solution {
public:
    int dp(vector<int>& nums, int i, vector<int>& t) {
        if (i >= nums.size() - 1)
            return 0;
        if (t[i] != -1)
            return t[i];
        int temp = 1e9;
        for (int j = 1; j <= nums[i]; j++) {
            temp = min(temp, 1 + dp(nums, i + j, t));
        }
        return t[i] = temp;
    }
    int jump(vector<int>& nums) {
        vector<int> t(nums.size() + 1, -1);
        return dp(nums, 0, t);
    }
};