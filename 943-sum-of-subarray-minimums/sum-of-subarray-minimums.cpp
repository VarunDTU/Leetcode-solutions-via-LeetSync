class Solution {
    int mod = 1e9 + 7;

public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> left(arr.size()), right(arr.size());
        stack<pair<int, int>> q; // element , count
        for (int i = 0; i < arr.size(); i++) {
            int count = 1;
            while (!q.empty() && q.top().first >= arr[i]) {
                count += q.top().second;
                q.pop();
            }
            left[i] = count;
            q.push({arr[i], count});
        }
        while (!q.empty())
            q.pop();
        for (int i = arr.size() - 1; i >= 0; i--) {
            int count = 1;
            while (!q.empty() && q.top().first > arr[i]) {
                count += q.top().second;
                q.pop();
            }
            right[i] = count;
            q.push({arr[i], count});
        }
       
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            ans += (((long long)(left[i] * right[i]) % mod) * arr[i]%mod) % mod;
            ans%=mod;
        }
        return ans;
    }
};