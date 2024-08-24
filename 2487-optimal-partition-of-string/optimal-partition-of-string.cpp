class Solution {
public:
    int partitionString(string s) {
        set<int>mp;
        int count=0,st=0,e=0;
        while(st<=e&&e<s.size()){
            if(mp.find(s[e])==mp.end()){
                mp.insert(s[e]);
                e++;
            }
            else{
                mp.clear();
                count++;
                st=e;
                
            }
        }
        if(!mp.empty())count++;
        return count;
    }
};