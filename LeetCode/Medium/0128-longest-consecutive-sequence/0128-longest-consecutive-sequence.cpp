class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       if (nums.empty())
        {
            return 0;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int max_count{1}, count{1};

        for (int i{}; i < n - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                continue;
            }
            if (nums[i] + 1 == nums[i + 1])
            {
                count++;
            }
            else
            {
                max_count = max(max_count, count);
                count = 1;
            }
        }
        return max(max_count, count);
    }
};