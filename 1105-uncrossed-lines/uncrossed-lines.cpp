class Solution {
    int t[501][501];
    int helper(vector<int>& s1, vector<int>& s2, int n, int m) {
        if (t[n][m] != -1) {
            return t[n][m];
        }
        if (n == 0 || m == 0) {
            return t[n][m] = 0;
        }

        if (s1[n - 1] == s2[m - 1]) {
            return t[n][m] = 1 + helper(s1, s2, n - 1, m - 1);
        } else {

            return t[n][m] =
                       max(helper(s1, s2, n - 1, m), helper(s1, s2, n, m - 1));
        }
    }

public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(t, -1, sizeof(t));
        return helper(nums1, nums2, nums1.size() , nums2.size() );
    }
};