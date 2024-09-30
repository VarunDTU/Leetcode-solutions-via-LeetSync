class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ' ')) {

            if (token.size() != 0) {
                tokens.push_back(token);
            }
        }
        string ans = "";

        for (int i = 0; i < tokens.size(); i++) {

            ans += tokens[tokens.size() - i - 1];
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};