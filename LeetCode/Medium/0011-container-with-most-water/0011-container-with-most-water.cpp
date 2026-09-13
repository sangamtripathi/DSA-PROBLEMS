class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int maxi = 0;

        while (start < end) {
            int current_h = min(height[start], height[end]);

            maxi = max(maxi, current_h * (end - start));

            while (start < end && height[start] <= current_h) {
                start++;
            }

            while (start < end && height[end] <= current_h) {
                end--;
            }
        }

        return maxi;
    }
};