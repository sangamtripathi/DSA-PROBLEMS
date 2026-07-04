class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int can1{};
        int can2{1};
        int count1{};
        int count2{};
        for (int i{}; i < nums.size(); ++i)
        {
            if (can1 == nums[i])
            {
                count1++;
            }
            else if (can2 == nums[i])
            {
                count2++;
            }
            else if (count1 == 0)
            {
                can1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                can2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int num : nums)
        {
            if (num == can1)
                count1++;
            else if (num == can2)
                count2++;
        }

        vector<int> result;
        if (count1 > nums.size() / 3)
            result.push_back(can1);
        if (count2 > nums.size() / 3)
            result.push_back(can2);

        return result;
    }
};