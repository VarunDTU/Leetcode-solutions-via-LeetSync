class Solution {
    vector<vector<string>>nQueens;
    void helper(int row,vector<string>pos){
        if(row==pos.size()){
            nQueens.push_back(pos);
        }
        for(int i=0;i<pos.size();i++){
            if(isValid(pos,row,i)){
            pos[row][i]='Q';
                helper(row+1,pos);
            pos[row][i]='.';   
            }
        }
    }
    bool isValid(vector<string>board,int x,int y){
        //row is already unique
        for(int i=0;i<x;i++){
            if(board[i][y]=='Q')return false;
        }
        
        for(int i=x,j=y;j>=0&&i>=0;i--,j--){
            if(board[i][j]=='Q')return false;
        }
        for(int i=x,j=y;j>=0&&i>=0;i--,j++){
            if(board[i][j]=='Q')return false;
        }
    return true;

    }
public:

    vector<vector<string>> solveNQueens(int n) {
        vector<string>chessboard(n,string(n,'.'));
        nQueens={};
        helper(0,chessboard);
        return nQueens;
    }
};