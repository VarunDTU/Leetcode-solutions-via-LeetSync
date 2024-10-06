class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss(s1);
        stringstream ss2(s2);
        string token;
        deque<string> sen1, sen2;

        while (getline(ss, token, ' ')) {

            if (token.size() != 0) {
                sen1.push_back(token);
            }
        }
        while (getline(ss2, token, ' ')) {

            if (token.size() != 0) {
                sen2.push_back(token);
            }
        }

        int st1 = 0, st2 = 0;

    
        while (sen1.size() > 0 && sen2.size() > 0 &&
               sen1.front() == sen2.front()) {
            sen1.pop_front();
            sen2.pop_front();
        }
        while (sen1.size() > 0 && sen2.size() > 0 &&
               sen1.back() == sen2.back()) {
            sen1.pop_back();
            sen2.pop_back();
        }
        return sen1.size()==0||sen2.size() == 0 ? true : false;
    }
};