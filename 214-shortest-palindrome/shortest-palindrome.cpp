class Solution {
public:
    string shortestPalindrome(string s) {
        string ss=s+'#';
        string rev=s;
        reverse(rev.begin(),rev.end());
        ss+=rev;
        vector<int>kmp(ss.size(),0);
        int i=1,k=0;
        while(i<ss.size()){
            if(ss[i]==s[k]){
                k++;
                kmp[i]=k;
                i++;
            }
            else {
                if(k>0)k=kmp[k-1];
                else kmp[i]=0,i++;
            }
        }

        return string(s.rbegin(),s.rend()).substr(0,s.size()-kmp.back())+s;

    }
};