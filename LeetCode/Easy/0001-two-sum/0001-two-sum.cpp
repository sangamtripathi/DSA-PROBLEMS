class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int,int>mpp;
        
        for(int i{};i<n;++i){
            int subtract =target-nums[i];
            if(mpp.find(subtract)!=mpp.end()){
                return {mpp[subtract],i};
            }
            mpp[nums[i]]=i;
        }
        return result;
    }
};