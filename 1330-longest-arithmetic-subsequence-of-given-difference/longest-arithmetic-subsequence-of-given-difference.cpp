class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int>dp;
        int ans=1;
        for(int i=0;i<arr.size();i++){
            int num=arr[i];
            if(dp.find(num-diff)!=dp.end()){
                dp[num]=dp[num-diff]+1;
            }
            else{
                dp[num]=1;
            }
            ans=max(ans,dp[num]);
        }
        return ans;
    }
};