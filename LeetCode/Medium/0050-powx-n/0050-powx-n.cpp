class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        double ans{1};

        if (power < 0) {
            power = -power;
        }

        while (power > 0) {
            if (power % 2 == 1) {
                ans *= x;
                power = power - 1;
            } else {
                power /= 2;
                x *= x;
            }
        }

        if (n < 0) {
            ans = 1.0 / ans;
        }

        return ans;
    }
};