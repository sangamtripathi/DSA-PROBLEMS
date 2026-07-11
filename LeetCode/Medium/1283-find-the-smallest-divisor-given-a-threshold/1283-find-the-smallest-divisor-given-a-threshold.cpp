class Solution {
public:
    long long check(vector<int>& nums, int mid) {
        long long sum{};
        for (int i{}; i < nums.size(); ++i) {
            long long rem = (nums[i] + mid - 1) / mid;
            sum += rem;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low{1};
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long sum = check(nums, mid);
            if (sum <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};