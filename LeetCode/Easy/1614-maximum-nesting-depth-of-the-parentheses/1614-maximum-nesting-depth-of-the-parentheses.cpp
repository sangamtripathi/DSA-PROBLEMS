class Solution {
public:
    int maxDepth(string s) {
        int para{};
        int depth{};

        for (int i{}; i < s.length(); ++i) {
            if (s[i] == '(') {
                para++;
            } else if (s[i] == ')') {
                para--;
            }

            depth = max(depth, para);
        }
        return depth;
    }
};