class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int swaping=nums.size()-1;
        int i{};
        while(i<=swaping){
            if(nums[i]==val){
                swap(nums[i],nums[swaping]);
                swaping--;
            }
            else{
                i++;
            }
            
        }
        return swaping+1;
    }
};