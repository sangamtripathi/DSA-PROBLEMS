class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();    

        for (int i{}; i < m-1; ++i)
        {
            for (int j{i + 1}; j < m; ++j)
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