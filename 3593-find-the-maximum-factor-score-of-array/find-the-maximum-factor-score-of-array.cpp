class Solution {
public:
    long long maxScore(vector<int>& nums) {
        long long g = nums[0], l = nums[0];
        for (auto itr : nums)
            g = gcd(g, itr), l = (l * itr) / gcd(l, itr);
        long long ans = g * l;
        if (nums.size() == 1)
            return nums[0] * nums[0];
        for (auto itr : nums) {
            vector<int> x = nums;
            auto pos = find(x.begin(), x.end(), itr);
            x.erase(pos);
            g = x[0], l = x[0];
            for (auto itr : x)
                g = gcd(g, itr), l = (l * itr) / gcd(l, itr);
            ans = max(ans, g * l);
        }
        return ans;
    }
};