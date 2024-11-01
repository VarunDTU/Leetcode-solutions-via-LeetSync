class Solution {
public:
    string makeFancyString(string s) {

        if(s.size()<=2)return s;
        string ans="";
        ans+=s[0];
        ans+=s[1];
        for(int i=2;i<s.size();i++){
            //cout<<s[i-2]<<s[i-1]<<s[i]<<endl;
            if(s[i-1]!=s[i]||s[i-2]!=s[i])ans+=s[i];
            //cout<<ans<<endl;
        }
        return ans;
    }
};