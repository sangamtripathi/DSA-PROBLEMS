class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Edge case: no strings at all
        if (strs.empty())
            return "";

        // Step 1: assume the first string is fully the prefix,
        // then shrink it as we find mismatches
        string prefix = strs[0];

        // Step 2: compare 'prefix' against every other string
        for (int i = 1; i < strs.size(); i++) {
            prefix = commonPrefix(prefix, strs[i]);

            // Optimization: if prefix ever becomes empty,
            // no point checking further
            if (prefix.empty())
                return "";
        }

        return prefix;
    }

private:
    // Helper: find common prefix between two strings only
    string commonPrefix(const string& a, const string& b) {
        int i = 0;
        int minLen = min(a.length(), b.length());

        while (i < minLen && a[i] == b[i]) {
            i++;
        }

        return a.substr(0, i); // first i chars match
    }
};