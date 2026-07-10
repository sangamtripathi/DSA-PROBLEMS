class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
    int low{};
    int high{n - 1};

    while (low < high) {
      int mid = (low + high) / 2;

      if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
        low = low + 1;
        high = high - 1;
        continue;
      }

      if (nums[high] < nums[mid]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return nums[low];
    }
};