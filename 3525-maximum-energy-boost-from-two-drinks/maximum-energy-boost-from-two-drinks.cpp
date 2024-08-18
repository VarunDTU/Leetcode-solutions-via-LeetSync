class Solution {
    vector<vector<long long>>dp;
public:
long long helper(vector<int>& a, vector<int>& b,int i,int flag){
    if(i>=a.size())return 0;
    if(dp[i][flag]!=-1)return dp[i][flag];
    long long boost=flag?a[i]:b[i];
    return dp[i][flag]=boost+ max(helper(a,b,i+1,flag),helper(a,b,i+2,!flag));
}
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        dp.resize(a.size()+1,vector<long long>(2,-1));
        return max(helper(a,b,0,true),helper(a,b,0,false));
    }
};