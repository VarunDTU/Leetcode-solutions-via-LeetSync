class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int>dic(3,0);
        for(auto itr:s)dic[itr-'a']++;
        int ans=s.size(),n=s.size();
        if(dic[0]<k||dic[1]<k||dic[2]<k)return -1;
        int i=0,j=0;
        while(i<s.size()){
            dic[s[i]-'a']--;
            while(dic[s[i]-'a']<k){
                dic[s[j]-'a']++;
                j++;
            }
            i++;
            ans=min(ans,n-i+j);
        }
        return ans;
    }
};