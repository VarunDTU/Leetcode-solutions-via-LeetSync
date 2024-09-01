class Solution {
public:
    int minAddToMakeValid(string s) {
        int st=0, count=0;
        for(int itr:s){
            if(itr=='(')st++;
            else if(st>0)st--;
            else count++;
        }
        count+=st;
        return count;
    }
};