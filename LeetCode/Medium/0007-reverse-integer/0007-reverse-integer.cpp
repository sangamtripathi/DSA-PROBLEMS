// This executes once globally before LeetCode runs any test cases
const auto speedup = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

// YOU CAN IGNORE THE CODE ABOVE ITS JUST TO MAKE IT COMPILE FASTER

class Solution {
public:
    int reverse(int x) {
        long long revn = 0;
        
        while (x != 0) {
            // No division checks here anymore, just pure math
            revn = (revn * 10) + (x % 10);
            x /= 10;
        }
        
        // Single boundary check at the very end
        if (revn > INT_MAX || revn < INT_MIN) {
            return 0;
        }
        
        return static_cast<int>(revn);
    }
};