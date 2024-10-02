class Solution {
    vector<vector<int>>dp;
    int helper(vector<vector<int>>& pairs,int idx,int prev){
        if(idx==pairs.size())return 0;
        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
        if(prev==-1||pairs[prev][1]<pairs[idx][0])return dp[idx][prev+1]= max(1+helper(pairs,idx+1,idx),helper(pairs,idx+1,prev));
        return dp[idx][prev+1]= helper(pairs,idx+1,prev);
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        dp.resize(pairs.size(),vector<int>(pairs.size()+1,-1));
        sort(pairs.begin(),pairs.end());
        return helper(pairs,0,-1);
    }
};