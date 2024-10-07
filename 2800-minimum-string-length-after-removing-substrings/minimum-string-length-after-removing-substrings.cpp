class Solution {
public:
    int minLength(string s) {
        stack<int>st;
        for(auto itr:s){
            if(!st.empty()&&st.top()=='A'&&itr=='B')st.pop();
            else if(!st.empty()&&st.top()=='C'&&itr=='D')st.pop();
            else st.push(itr);
        }
        return st.size();
    }
};