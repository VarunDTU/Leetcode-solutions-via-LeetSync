class Solution {
public:
//(u(love)
    string reverseParentheses(string s) {
        vector<int>op;
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')op.push_back(i);
            else if(s[i]==')'){
                int index=op.back();
                reverse(s.begin()+index+1,s.begin()+i);
                op.pop_back();
            }
        }
        for(auto itr:s){
            if(itr!='('&&itr!=')')ans+=itr;
        }
        return ans;
    }
};