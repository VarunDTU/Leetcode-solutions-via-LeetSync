class Solution {
public:
    long long minimumSteps(string s) {
        int st=0;
        long long swaps=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')st++;
            else swaps+=st;
        }
        return swaps;
    }
};