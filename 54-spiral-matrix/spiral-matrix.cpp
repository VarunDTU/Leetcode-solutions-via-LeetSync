class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1, top = 0,
            bottom = matrix.size() - 1;
        vector<int> v;
        while (left <= right && top <= bottom) {

            for (int i = left; i <= right && top <= bottom; i++) {
                v.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom && left <= right; i++) {
                v.push_back(matrix[i][right]);
            }

            right--;

            for (int i = right; i >= left && top <= bottom; i--) {
                v.push_back(matrix[bottom][i]);
            }

            bottom--;

            for (int i = bottom; i >= top && left <= right; i--) {
                v.push_back(matrix[i][left]);
            }
            left++;
        }
        return v;
    }
};