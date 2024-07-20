class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = (n > 0) ? matrix[0].size() : 0;
        int top = 0, left = 0, right = m - 1, bottom = n - 1, i;
        vector<int> a;
        while (top <= bottom && left <= right) {
            for (i = left; i <= right; i++) {
                a.push_back(matrix[top][i]);
            }
            top++;
            for (i = top; i <= bottom; i++) {
                a.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                for (i = right; i >= left; i--) {
                    a.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                for (i = bottom; i >= top; i--) {
                    a.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return a;
    }
};
