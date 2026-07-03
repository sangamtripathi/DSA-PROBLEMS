class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();    // ROWS
        int n = matrix[0].size(); // COLUMNS

        for (int i{}; i < m; ++i)
        {
            for (int j{i + 1}; j < n; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i{}; i < m; ++i)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};