class Solution {
public:
    int minExtraChar(string s, vector<string>& dic) {
        set<string>st(dic.begin(),dic.end());
        vector<int>dp(s.size()+1,s.size()+1);
        dp[0]=0;
        for(int i=1;i<=s.size();i++){
            dp[i]=dp[i-1]+1;
            for(int j=1;j<=i;j++){
                if(st.find(s.substr(i-j,j))!=st.end()){
                    dp[i]=min(dp[i],dp[i-j]);
                }
            }
        }
        return dp[dp.size()-1];
    }
};