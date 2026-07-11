class Solution {
public:
    bool check(vector<int>& arr, int m, int k, int mid) {
        int cnt{};
        int b{};

        for (int i{}; i < arr.size(); ++i) {
            if (arr[i] <= mid) {
                cnt++;
            } else {
                b += cnt / k;
                cnt = 0;
            }
        }
        b += cnt / k;

        return b >= m;
    }
    int minDays(vector<int>& bloomday, int m, int k) {
        if ((long long)m * (long long)k > bloomday.size()) {
            return -1;
        }
        int low = *min_element(bloomday.begin(), bloomday.end());
        int high = *max_element(bloomday.begin(), bloomday.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool possible = check(bloomday, m, k, mid);

            if (possible) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};