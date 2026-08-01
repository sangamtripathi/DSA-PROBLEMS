class Solution {
public:
    int romanToInt(string s) {
        int ans{};
        std::unordered_map<char, int> roman = {
            {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};

        for (int i = s.length() - 1; i >= 0; --i) {
            if (i != 0) {
                if (roman[s[i]] > roman[s[i - 1]]) {
                    ans += roman[s[i]] - roman[s[i - 1]];
                    i--;
                } else {
                    ans += roman[s[i]];
                }
            } else {
                ans += roman[s[i]];
            }
        }
        return ans;
    }
};