class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
    int low{};
    int high{n - 1};

    while (low < high) {
      int mid = (low + high) / 2;

      if (nums[low] <= nums[high]) {
        break;
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