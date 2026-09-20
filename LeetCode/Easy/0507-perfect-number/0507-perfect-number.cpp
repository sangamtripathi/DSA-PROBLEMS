class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum{};

        for (int i{1}; i < sqrt(num); ++i) {
            if (num % i == 0) {
                sum += i;
                if (num / i != num) {
                    sum += (num / i);
                }
            }
        }

        if(sum==num){
            return true;
        }else{
            return false;
        }
    }
};