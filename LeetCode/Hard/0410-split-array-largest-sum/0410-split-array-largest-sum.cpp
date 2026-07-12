class Solution {
public:
    bool place(vector<int>& nums, int k, int mid) {
        int sum{};
        int cnt{};
        for (int i{}; i < nums.size(); ++i) {
            if (nums[i] > mid) {
                return false;
            }
            if (sum + nums[i] > mid) {
                cnt++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return cnt + 1 <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low{*max_element(nums.begin(), nums.end())};
        int high{};
        for (int x : nums) {
            high += x;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (place(nums, k, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};