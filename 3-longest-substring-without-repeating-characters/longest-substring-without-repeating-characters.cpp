class Solution {
    
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>dic;
        int st=0,e=0,n=s.size(),ans=0;

        while(e<n){
            dic[s[e]]++;
            while(dic[s[e]]!=1){
               
                dic[s[st]]--;
                st++;
            }
            ans=max(ans,e-st+1);
            e++;
        }
        return ans;

    }
};