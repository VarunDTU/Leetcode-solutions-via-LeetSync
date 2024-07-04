class Solution {
public:
    // min :max(weights)
    // max:sum(weights)
    // O(n*(max-min))

    int shipWithinDays(vector<int>& weights, int days) {
        int minW = INT_MIN, maxW = 0;
        int ans = 0;
        for (auto itr : weights) {
            minW = max(itr, minW);
            maxW += itr;
        }

        // s->minW, end->maxW
        while (minW <= maxW) {
            int midW = minW + (maxW - minW) / 2;
            int currentdays = 1, current = 0;

            for (auto w : weights) {
                current += w;
                if (current > midW) {
                    currentdays++;
                    current = w;
                }
            }

            if (currentdays > days)
                minW = midW + 1;
            else {
                ans = midW;
                maxW = midW - 1;
            }
        }
        return ans;
    }
};