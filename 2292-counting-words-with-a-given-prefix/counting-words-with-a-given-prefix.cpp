class Solution {
    bool counting(string str,string pref){
        if(str.size()<pref.size())return false;
        for(int i=0;i<pref.size();i++){
            if(str[i]!=pref[i])return false;
        }
        return true;
    }
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            if(counting(words[i],pref))ans++;

        }
        return ans;
    }
};