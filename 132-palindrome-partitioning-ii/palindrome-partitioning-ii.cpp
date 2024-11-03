class Solution {
    int dp[2001];
    bool palindrome(string &s,int start,int end){
        while(start<end){
            if(s[start]!=s[end])return false;
            start++,end--;
        }
        return true;
    }
    int helper(string &s,int idx){
        if(idx==s.size())return 0;
        if(dp[idx]!=-1)return dp[idx];
        int mini=INT_MAX;
        for(int i=idx;i<s.size();i++){
            if(palindrome(s,idx,i)){
                mini=min(mini,1+helper(s,i+1));
            }
        }
        return dp[idx]=mini;
    }
public:
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return helper(s,0)-1;
    }
};