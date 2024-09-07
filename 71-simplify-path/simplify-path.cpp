class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string temp = "";
        for (int i = 0; i < path.size(); i++) {
            if (path[i] != '/') {
                while (i < path.size() && path[i] != '/') {
                    temp += path[i];
                    i++;
                }
                if (temp == "..") {
                    if (!st.empty())
                        st.pop_back();
                } else if (temp != ".")
                    st.push_back(temp);
                temp = "";
            }
        }
        
        for (int i = 0; i < st.size(); i++) {
            temp += '/';
            temp += st[i];
        }
     
        return temp.size()==0?"/":temp;
    }
};