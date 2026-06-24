#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        // Traverse the vector from the last element to the first
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits; // Return early if no carry is needed
            }
            // If the digit is 9, it becomes 0 due to the carry
            digits[i] = 0;
        }
        
        // If the loop finished, it means all digits were 9 (e.g., [9, 9, 9])
        // We insert a '1' at the very beginning to get [1, 0, 0, 0]
        digits.insert(digits.begin(), 1);
        return digits;
    }
};