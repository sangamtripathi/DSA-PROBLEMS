class Solution {
public:
    bool isPalindrome(int x) {
        // A negative number cannot be a palindrome
        if (x < 0) {
            return false;
        }

        long long revn = 0;
        long long y = x;
        
        while (y != 0) {
            revn = (revn * 10) + (y % 10);
            y /= 10;
        }
        
        return x == revn;
    }
};