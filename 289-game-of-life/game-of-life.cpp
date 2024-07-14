class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row[] = {-1,1,0,0,-1,-1,1,1},
            col[]=  {0,0,-1,1,-1,1,-1,1};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int alive = 0;
                for (int k = 0; k < 8; k++) {
                    int new_row = i + row[k];
                    int new_col = j + col[k];
                    if (new_row < board.size() && new_row >= 0 &&
                        new_col < board[0].size() && new_col >= 0 &&
                        (board[new_row][new_col] == 1||board[new_row][new_col] == -2)) {
                        alive++;
                    }
                }

                if (alive < 2&&board[i][j]==1)
                    board[i][j] = -2;
                else if (alive == 3&&board[i][j]==0)
                    board[i][j] = -1;
                else if (alive > 3&&board[i][j]==1)
                    board[i][j] =-2;
            }
        }
        for (auto& itr : board) {
            for (auto& itr2 : itr) {
                
                if (itr2 == -1)
                    itr2 = 1;
                else if (itr2 == -2)
                    itr2 = 0;
            }
          
        }
    }
};