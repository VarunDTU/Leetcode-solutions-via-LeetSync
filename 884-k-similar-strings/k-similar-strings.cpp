class Solution {
    unordered_map<string,int>t;
    int dp(string s1, string s2, int i) {
        if (i == s1.size())
            return 0;
       if(t.find(s2)!=t.end())return t[s2];
        if (s1[i] == s2[i])
            return t[s2]= dp(s1, s2, i + 1);
        int ans = INT_MAX;
        for (int j = i+1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                swap(s2[i], s2[j]);
                ans = min(ans, 1+dp(s1, s2, i + 1));
                swap(s2[j], s2[i]);
            }
        }

        return t[s2]=ans;
    }

public:
    int kSimilarity(string s1, string s2) { 
    
        return dp(s1, s2, 0); }
};