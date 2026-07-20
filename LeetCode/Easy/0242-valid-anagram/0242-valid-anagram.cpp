class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int n = s.length();
        map<char, int> mpp;
        map<char, int> mpp1;

        for (int i{}; i < n; ++i) {
            if (mpp.find(s[i]) != mpp.end()) {
                mpp[s[i]]++;
            } else {
                mpp[s[i]] = 1;
            }
            if (mpp1.find(t[i]) != mpp1.end()) {
                mpp1[t[i]]++;
            } else {
                mpp1[t[i]] = 1;
            }
        }

        for (int i{}; i < n; ++i) {
            if (mpp[s[i]] == mpp1[s[i]]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};