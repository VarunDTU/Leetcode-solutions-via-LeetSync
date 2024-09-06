class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n - 1, up = 0, down = n - 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int x = 1;
        while (x <= n * n) {
            cout << x;
            for (int i = left; i <= right; i++) {
                if (x > n * n)
                    break;
                ans[up][i] = x;
                x++;
            }
            if (x > n * n)
                break;
            up++;
            for (int i = up; i <= down; i++) {
                if (x > n * n)
                    break;
                ans[i][right] = x;
                x++;
            }

            right--;

            for (int i = right; i >= left; i--) {
                if (x > n * n)
                    break;
                ans[down][i] = x;
                x++;
            }

            down--;
            for (int i = down; i >= up; i--) {
                if (x > n * n)
                    break;
                ans[i][left] = x;
                x++;
            }
            left++;
        }
        return ans;
    }
};