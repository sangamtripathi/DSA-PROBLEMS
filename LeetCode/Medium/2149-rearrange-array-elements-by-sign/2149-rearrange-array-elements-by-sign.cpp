class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      
        int n = nums.size();
        vector<int> result(n, 0);
        int positive{}, negative{1};
        for (int i{}; i < n; ++i)
        {
            if (nums[i] > 0)
            {
                result[positive]=nums[i];
                positive+=2;
            }
            else
            {
                result[negative]=nums[i];
                negative+=2;
            }
        }
        return result;
    }
};