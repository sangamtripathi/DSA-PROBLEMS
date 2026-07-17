class Solution {
public:
    string removeOuterParentheses(string s) {
        string result{};
        result.reserve(s.length());
        int cnt{};

        for (char ch : s) {
            if (ch == '(' && cnt++ > 0)
                result += ch;
            if (ch == ')' && --cnt > 0)
                result += ch;
        }
        return result;
    }
};