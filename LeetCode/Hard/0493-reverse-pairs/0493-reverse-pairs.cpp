class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
      if (arr[left] <= arr[right]) {
        temp.push_back(arr[left]);
        left++;
      } else {
        temp.push_back(arr[right]);
        right++;
      }
    }

    while (left <= mid) {
      temp.push_back(arr[left]);
      left++;
    }
    while (right <= high) {
      temp.push_back(arr[right]);
      right++;
    }

    for (int i = low; i <= high; ++i) {
      arr[i] = temp[i - low];
    }
  }

  int countpairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt{};
    for (int i{low}; i <= mid; ++i) {
      while (right <= high && arr[i] > 2LL * arr[right]) {
        right++;
      }
      cnt += right - (mid + 1);
    }
    return cnt;
  }

  int merge_sort(vector<int> &arr, int low, int high) {
    int cnt{};

    if (low >= high)
      return cnt; // This handles empty arrays (0 elements) safely!

    if (low == high) {
      return cnt;
    }
    int mid = (high + low) / 2;

    cnt += merge_sort(arr, low, mid);
    cnt += merge_sort(arr, mid + 1, high);

    cnt += countpairs(arr, low, mid, high);

    merge(arr, low, mid, high);
    return cnt;
  }
  int reversePairs(vector<int> &nums) {
    int cnt{};
    int n = nums.size();

    cnt += merge_sort(nums, 0, n - 1);
    return cnt;
  }
};