class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            long long sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                sum=sum%(1000000007);
                ans.push_back(sum);
            }
        }
        int sum = 0;
        sort(ans.begin(), ans.end());
        for (int i = left - 1; i < right; i++) {
            sum += ans[i];
            sum=sum%(1000000007);
        }
        return sum;
    }
};