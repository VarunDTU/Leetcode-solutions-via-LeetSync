class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int st=0;
        for(int i=0;i<s.size();i++){
            if(spaces.size()>st&&spaces[st]==i)ans+=' ',st++;
            ans+=s[i];
        }
        return ans;
    }
};