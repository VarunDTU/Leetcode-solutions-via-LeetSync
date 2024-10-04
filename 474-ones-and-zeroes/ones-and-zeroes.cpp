class Solution {
    vector<vector<vector<int>>>dp;
    int helper(vector<pair<int,int>>&res,int m,int n,int idx){
        if(idx==res.size())return 0;
        if(m==0&&n==0)return 0;
        if(dp[m][n][idx]!=-1)return dp[m][n][idx];
        if(res[idx].first<=m&&res[idx].second<=n){
            return dp[m][n][idx]= max(helper(res,m-res[idx].first,n-res[idx].second,idx+1)+1,helper(res,m,n,idx+1));
        }
        return dp[m][n][idx]= helper(res,m,n,idx+1);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>res;
        for(auto itr:strs){
            int z=0,o=0;
            for(auto ch:itr){
                if(ch=='0')z++;
                else o++;
            }
            res.push_back({z,o});
        }
        dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));
        return helper(res,m,n,0);



    }
};