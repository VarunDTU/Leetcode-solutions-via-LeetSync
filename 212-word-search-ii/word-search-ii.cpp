class TrieNode {
    public:
    TrieNode* dic[26]={NULL};
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (auto itr : dic)
            itr = NULL;

    }
};

class Solution {
    void insert(string word, TrieNode* root) {

        for (char ch : word) {
            if (!root->dic[ch - 'a']) {
                root->dic[ch - 'a'] = new TrieNode();
            }
            root = root->dic[ch - 'a'];
        }
        root->isEnd = true;
    }
    const int row[4]={-1,0,1,0},col[4]={0,-1,0,1};
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int i,int j,TrieNode* root,string temp,vector<string>&ans){
        
        if(!root)return ;
        if(root->isEnd){
            ans.push_back(temp);
            root->isEnd=false;
        }
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int newRow=i+row[k],newCol=j+col[k];
            if(newRow<board.size()&&newCol<board[0].size()&&!vis[newRow][newCol]&&root->dic[board[newRow][newCol]-'a']){
                dfs(board,vis,newRow,newCol,root->dic[board[newRow][newCol]-'a'],temp+board[newRow][newCol],ans);
            }
            
        }
        vis[i][j]=false;



    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* head = new TrieNode();

        for (auto itr : words)
            insert(itr, head);
        
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),false));
        vector<string>ans;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                //if(head->dic[board[i][j]-'a']){};
                string temp;
                temp+=board[i][j];
                    dfs(board,vis,i,j,head->dic[board[i][j]-'a'],temp,ans);
                
            }
        }

        return ans;


    }
};