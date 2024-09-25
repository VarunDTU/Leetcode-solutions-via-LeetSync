struct TrieNode{
        TrieNode* child[26]={};
        int cnt=0;
};
class Solution {
    TrieNode root;
public:
    void insert(string word){
        auto temp=&root;
        for(char itr:word){
            if(!temp->child[itr-'a']){
                temp->child[itr-'a']=new TrieNode();
            }
            temp->child[itr-'a']->cnt++;
            temp=temp->child[itr-'a'];
        }
    }
    int prefix(string word){
        int count=0;
        TrieNode* temp=&root;
        for(auto itr:word){
            count+=temp->child[itr-'a']->cnt;
            temp=temp->child[itr-'a'];
        }
        return count;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        for(auto itr:words)insert(itr);
        vector<int>ans;
        for(auto itr:words){
            ans.push_back(prefix(itr));
        }
        return ans;
    }
};