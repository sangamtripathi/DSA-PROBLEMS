class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long int xorr;

        for(int val : nums){
            xorr^=val;
        }

        long int rightmost=(xorr&xorr-1)^xorr;

        int b1{};
        int b2{};

        for(int val:nums){
            if(rightmost & val){
                b1^=val;
            }else{
                b2^=val;
            }
        }

        return {b1,b2};
    }
};