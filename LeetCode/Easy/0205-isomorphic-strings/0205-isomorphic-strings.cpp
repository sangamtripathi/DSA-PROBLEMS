class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> mpp;
        unordered_set<char> used_in_t;
        int n = s.length();

        for (int i{}; i < n; ++i) {
            if (mpp.find(s[i]) != mpp.end()) {
                if (t[i] == mpp[s[i]]) {
                    continue;
                } else {
                    return false;
                }
            } else {
                if (used_in_t.find(t[i]) != used_in_t.end()) {
                    return false;
                } else {
                    mpp[s[i]] = t[i];
                    used_in_t.insert(t[i]);
                }
            }
        }
        return true;
    }
};