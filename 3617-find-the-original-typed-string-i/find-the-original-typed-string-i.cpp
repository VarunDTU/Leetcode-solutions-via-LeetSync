class Solution {
public:
    int possibleStringCount(string word) {
        int ans=0,st=0;
        for(int i=1;i<word.size();i++){
            while(i<word.size()&&word[st]==word[i])ans++,i++;
            st=i;
        }
        return ans+1;
    }
};