class Solution {
public:
    int minDays(vector<int>& bloom, int m, int k) {
        // k is number of flowers
        // m bouq

        if ((long)m * k > bloom.size())
            return -1;

        int mini = 1, ans, maxi = 1e9;
        while (mini <= maxi) {
            int mid = mini + (maxi - mini) / 2;
            int current = 0, tb = 0;
            for (int i = 0; i < bloom.size(); i++) {
                if (bloom[i] > mid) {
                    current = 0;
                } else {
                    current++;
                    if (current == k) {
                        tb++;
                        current = 0;
                    }
                }
            }

            if (tb < m) {
                mini = mid + 1;
            } else {
                maxi = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};