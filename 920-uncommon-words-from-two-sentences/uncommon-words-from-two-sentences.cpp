class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s,total=s1+" "+s2;
        stringstream ss(total);
        map<string,int>mp;
        while(getline(ss,s,' ')){
            mp[s]++;
        }
        vector<string>ans;
        for(auto itr:mp){
            if(itr.second==1)ans.push_back(itr.first);
        }
        return ans;
    }
};