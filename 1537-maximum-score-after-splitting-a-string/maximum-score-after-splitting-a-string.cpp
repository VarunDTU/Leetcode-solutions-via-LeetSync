class Solution {
public:
    int maxScore(string s) {
        int right=0,left=0;
        for(auto itr:s){
            if(itr=='1')right++;
        }
     int ans=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0')left++;
            else left--;
            ans=max(left+right,ans);
        }
        return ans;
    }
};