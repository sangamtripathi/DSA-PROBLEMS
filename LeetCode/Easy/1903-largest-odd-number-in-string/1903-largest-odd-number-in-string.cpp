class Solution {
public:
    string largestOddNumber(string num) {
        size_t found = num.find_last_of("13579");

        if (found != string::npos) {
            return num.substr(0, found + 1);
        }
        return "";
    }
};