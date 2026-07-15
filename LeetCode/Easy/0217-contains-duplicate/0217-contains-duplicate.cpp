class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mpp;
        for (int i{}; i < nums.size(); ++i) {
            if (mpp.find(nums[i]) != mpp.end()) {
                return true;
            } else {
                mpp[nums[i]] = i;
            }
        }
        return false;
    }
};