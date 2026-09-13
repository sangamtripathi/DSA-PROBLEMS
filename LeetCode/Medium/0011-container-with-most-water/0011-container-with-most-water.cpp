class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0){
            return 0;
        }
        int n=height.size();

        int start=0;
        int end=n-1;

        long int maxi{};
        while(start<end){
            long int temp=min(height[start],height[end])*(end-start);
            maxi=max(maxi,temp);

            if(height[start]<=height[end]){
                start++;
            }else{
                end--;
            }
        }

        return maxi;
    }
};