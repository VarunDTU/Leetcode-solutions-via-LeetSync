class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        int s=0,e=0;
        unordered_map<char,int>mp,curr;
        for(auto itr:s1)mp[itr]++;
        
        while(s<=e&&e<n2){
            curr[s2[e]]++;
            if(e-s+1==n1){
                if(mp==curr)return true;
            }
            if(e-s+1<n1){
                e++;
            }else{
                if(curr[s2[s]]==1)curr.erase(s2[s]);
                else curr[s2[s]]--;
                s++;
                e++;
            }
        }
        return false;
        
    }
};