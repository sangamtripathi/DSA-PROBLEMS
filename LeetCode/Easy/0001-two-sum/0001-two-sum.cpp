class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
         vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; i++) {
            numsWithIndex.push_back({nums[i], i});
        }
        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left{}, right{n - 1};

        while (right > left)
        {
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;

            if (sum < target)
            {
                left++;
            }
            else if (sum > target)
            {
                right--;
            }
            else
            {
                return {numsWithIndex[left].second , numsWithIndex[right].second};
            }
        }

        return {};
    }
};