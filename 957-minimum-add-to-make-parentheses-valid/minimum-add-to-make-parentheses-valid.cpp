class Solution {
public:
    int minAddToMakeValid(string s) {
        int st=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st++;
            else if(st>0)st--;
            else count++;
        }
        count+=st;
        return count;
    }
};