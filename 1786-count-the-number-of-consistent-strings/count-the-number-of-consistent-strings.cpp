class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>s(allowed.begin(),allowed.end());
        int ans=0;
        for(auto itr:words){
            bool flag=false;
            for(auto ch:itr){
                if(s.find(ch)==s.end()){flag=true;break;};
            }
            if(!flag)ans++;
        }
        return ans;
    }
};