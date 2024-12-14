class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>>mp(26,vector<int>(2,-1));

        int ans=0,mod = pow(10, 9) + 7;
        for(int i=0;i<s.length();i++){
            int c=s[i]-'A';
            ans=(ans+(i-mp[c][1])*(mp[c][1]-mp[c][0])%mod)%mod;
            mp[c][0]=mp[c][1];
            mp[c][1]=i;
        }
        for(int c=0;c<26;c++){
            ans=(ans+(s.size()-mp[c][1])*(mp[c][1]-mp[c][0])%mod)%mod;
        }
        return ans;
    }
};