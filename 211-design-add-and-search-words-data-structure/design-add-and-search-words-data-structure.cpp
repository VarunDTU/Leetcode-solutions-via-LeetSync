class Trie {
public:
    bool word;
    Trie* children[26];
    Trie() {
        word = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
    Trie* root = new Trie();

public:
    WordDictionary() {}

    void addWord(string word) {
        Trie* node = root;
        for (auto itr : word) {
            if (!node->children[itr - 'a']) {
                node->children[itr - 'a'] = new Trie();
            }
            node = node->children[itr - 'a'];
        }
        node->word = true;
    }

    bool search(string word) { return search(word, root); }
    bool search(string word, Trie* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.')
                node = node->children[word[i] - 'a'];
            else {
                Trie* temp = node;
                for (int j = 'a'; j <= 'z'; j++) {
                    node = temp->children[j - 'a'];
                    string s = word.substr(i + 1, word.size() - 1);
                    if (search(s, node))
                        return true;
                }
            }
        }
        return node && node->word;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */