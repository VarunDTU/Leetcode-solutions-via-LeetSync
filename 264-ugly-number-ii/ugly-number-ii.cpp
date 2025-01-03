class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)return 1;
        vector<int>dp(n);
        dp[0]=1;
        int two=0,three=0,five=0;
        for(int i=1;i<n;i++){
            dp[i]=min({2*dp[two],3*dp[three],5*dp[five]});
            if(dp[i]==dp[two]*2)two++;
            if(dp[i]==dp[three]*3)three++;
            if(dp[i]==dp[five]*5) five++;
       
        }
        return dp[n-1];
    }
};