class Solution {
    int helper(string s, int index, vector<int>& dp) {
        if (index == s.size())
            return 1;
        if (s[index] == '0')
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int ans = 0;
        if (s[index] != '0')
            ans += helper(s, index + 1, dp);
        if ((index + 1) < s.size()&&((s[index] == '1'&&
            s[index + 1] <= '9') || (s[index] == '2'&&
            s[index + 1] <= '6')))  
            ans += helper(s, index + 2, dp);
        return dp[index] = ans;
    }

public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1);
        return helper(s, 0, dp);
    }
};