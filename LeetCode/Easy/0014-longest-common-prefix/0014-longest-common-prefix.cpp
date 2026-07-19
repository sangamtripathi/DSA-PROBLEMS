class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int i{};
        string result{};
        sort(strs.begin(),strs.end());

        while (i < strs[0].length() && i < strs[n - 1].length()) {
            if (strs[0][i] == strs[n - 1][i]) {
                result+=(strs[0][i]);
                i++;
            } else {
                break;
            }
        }

        return result;
    }
};