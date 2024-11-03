class Solution {
public:
    int distinctEchoSubstrings(string text) {
        unordered_set<string> dic;
        for (int i = 1; i <= text.size() / 2; i++) {
            int count = 0;
            for (int first = 0, second = i; first < text.size() - i;
                 first++, second++) {
                if (text[first] == text[second])
                    count++;
                else
                    count = 0;
                if (count == i) {
                    dic.insert(text.substr(first - i + 1, i + 1)), count--;
                };
            }
        }
        return dic.size();
    }
};