class Solution {
public:
    int minimumLength(string s) {
        map<char,int>mp;
        for(auto itr:s)mp[itr]++;
        int ans=0;
        for(auto itr:mp){
            if(itr.second%2)ans+=itr.second-1;
            else ans+=itr.second-2;
        }
        return s.size()-ans;
    }
};