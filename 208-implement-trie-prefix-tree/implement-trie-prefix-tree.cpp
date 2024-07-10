class TrieNode {
public:
    TrieNode* cha[26];
    bool wordEnd;
    TrieNode() {
        wordEnd = false;
        for (auto& itr : cha)
            itr = NULL;
    }
};
class Trie {
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* p = root;
        for (char& itr : word) {
            if (!p->cha[(itr - 'a')])
                p->cha[(itr - 'a')] = new TrieNode();
            p = p->cha[(itr - 'a')];
        }
        p->wordEnd = true;
    }

    bool search(string word) {
        TrieNode* p = root;
        for (char& itr : word) {
            if (!p->cha[itr - 'a'])
                return false;
            p = p->cha[itr - 'a'];
        }
        return p->wordEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (char& itr : prefix) {
            if (!p->cha[itr - 'a'])
                return false;
            p = p->cha[itr - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */