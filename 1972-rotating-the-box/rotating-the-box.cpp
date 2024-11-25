class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        for (int i = 0; i < n; i++) {
            int base = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] != '.') {
                    if (box[i][j] == '*')
                        base = j;
                    ans[base][n-i-1]=box[i][j];
                    base--;
                }
            }
        }
        return ans;
    }
};