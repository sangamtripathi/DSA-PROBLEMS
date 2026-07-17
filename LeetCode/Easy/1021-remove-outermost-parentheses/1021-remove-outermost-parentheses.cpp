class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt{};
        string result{};
        for (int i{}; i < s.length(); ++i) {
            if (s[i] == '(') {
                if (cnt > 0) {
                    result += s[i];
                }
                cnt++;
            } else {
                cnt--;
                if (cnt > 0) {
                    result += s[i];
                }
            }
        }
        return result;
    }
};