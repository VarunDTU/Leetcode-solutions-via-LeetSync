class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& ban) {
        unordered_set<string>s(ban.begin(),ban.end());
        int count=0;
        for(auto itr:message){
            if(s.find(itr)!=s.end())count++;
            if(count==2)return true;
        }
        return false;
    }
};