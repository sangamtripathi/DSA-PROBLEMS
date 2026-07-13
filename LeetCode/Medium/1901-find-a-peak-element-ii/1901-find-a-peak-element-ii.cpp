class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {-1, -1};
        int n = matrix.size();
        int m = matrix[0].size();

        int low{};
        int high{m - 1};

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxi = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][mid] > matrix[maxi][mid]) {
                    maxi = i;
                }
            }
            int left = mid - 1 >= 0 ? matrix[maxi][mid - 1] : INT_MIN;
            int right = mid + 1 < m ? matrix[maxi][mid + 1] : INT_MIN;

            // Check if the middle element is greater than its neighbors
            if (matrix[maxi][mid] > left && matrix[maxi][mid] > right) {
                return {maxi, mid};
            } else if (left > matrix[maxi][mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};