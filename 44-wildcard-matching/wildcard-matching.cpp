class Solution {
    bool helper(string &s, string &p, int si, int pi, vector<vector<int>>& dp) {
        if (dp[si][pi] != -1)
            return dp[si][pi];
        if (si == s.size() && pi == p.size())
            return true;
        if (si == s.size()&&pi<p.size() && p[pi] == '*')
            return helper(s, p, si, pi + 1,dp);
        if (si == s.size() || pi == p.size())
            return false;
        if (s[si] == p[pi]||p[pi]=='?')
            return dp[si][pi] = helper(s, p, si + 1, pi + 1, dp);
        if (p[pi] == '*') {
           
            return dp[si][pi] = helper(s, p, si + 1, pi, dp) ||
                                helper(s, p, si, pi + 1, dp);
        }
       
        return false;
    }

public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return helper(s, p, 0, 0, dp);
    }
};