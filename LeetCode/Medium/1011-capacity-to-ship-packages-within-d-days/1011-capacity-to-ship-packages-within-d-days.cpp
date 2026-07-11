class Solution {
public:
    bool check(vector<int>& weights, int mid, int days) {
        int days_needed = 1; // Start on day 1
        int current_load = 0;

        for (int w : weights) {
            if (current_load + w > mid) {
                days_needed++;
                current_load = w;
            } else {
                current_load += w;
            }
        }

        return days_needed <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low{};
        int high{};
        for (int x : weights) {
            low = max(low, x);
            high += x;
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(weights, mid, days)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};