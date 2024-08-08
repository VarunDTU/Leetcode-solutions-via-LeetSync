class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        s.erase(beginWord);
        queue<pair<int, string>> q;
        q.push({1, beginWord});
        while (!q.empty()) {
            string word = q.front().second;
            int cost = q.front().first;
            q.pop();
            for (int j = 0; j < word.size(); j++) {
                char l = word[j];
                for (char i = 'a'; i <= 'z'; i++) {
                    word[j] = i;

                    if (s.find(word) != s.end()) {
                        if (word == endWord)
                            return cost + 1;
                        q.push({cost + 1, word});
                        s.erase(word);
                    }
                }
                word[j] = l;
            }
        }
        return 0;
    }
};