class Solution {
public:
    int appendCharacters(string s, string t) {
        int s_st=0,t_st=0;
        while(s_st<s.size()&&t_st<t.size()){
            if(s[s_st]==t[t_st]){
                t_st++;
            }
                s_st++;
        }
        return t.size()-t_st;
    }
};