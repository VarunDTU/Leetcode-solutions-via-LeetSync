class Solution {
    private:
        const int mod=1e9+7;
    int helper(int& low, int& high, int zero, int one, int length,
               vector<int>& dp) {
        if (length > high)
            return 0;
        if (dp[length] != -1)
            return dp[length];
        int ans = 0;
        if (length >= low && length <= high) {
            ans++;
        }
        ans += helper(low, high, zero, one, length + zero, dp);
        ans%=mod;
        ans += helper(low, high, zero, one, length + one, dp);
        
        return dp[length] = ans%mod;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return helper(low, high, zero, one, 0, dp);
    }
};