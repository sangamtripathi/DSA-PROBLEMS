class Solution {
public:
    vector<int> generaterow(int row) {
        long long ans = 1;
        vector<int> ansrow;
        ansrow.push_back(1);

        for (int col{1}; col < row; ++col) {
            ans *= (row - col);
            ans /= col;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
    vector<vector<int>> generate(int num) {
        vector<vector<int>> result;
        for (int i{}; i < num; ++i) {
            result.push_back(generaterow(i + 1));
        }

        return result;
    }
};