class Solution {
    bool helper(string &s, set<string>& dic,int idx,int start, vector<vector<int>>&dp){
        string temp=s.substr(start,idx-start+1);
        if(idx==s.size()){
            if(temp==""||dic.find(temp)!=dic.end())return true;
            return false;
        }
        if(dp[start][idx]!=-1)return dp[start][idx];
        if(dic.find(temp)==dic.end())return dp[start][idx]=helper(s,dic,idx+1,start,dp);
        
        return dp[start][idx]=(helper(s,dic,idx+1,start,dp)||helper(s,dic,idx+1,idx+1,dp));
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>dic(wordDict.begin(),wordDict.end());
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return helper(s,dic,0,0,dp);
        
    }
};