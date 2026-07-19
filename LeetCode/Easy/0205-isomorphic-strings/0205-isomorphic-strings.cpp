class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int last_seen_s[256] = {0};
        int last_seen_t[256] = {0};

        int n = s.length();

        for (int i = 0; i < n; ++i) {
            int char_s = static_cast<unsigned char>(s[i]);
            int char_t = static_cast<unsigned char>(t[i]);

            if (last_seen_s[char_s] != last_seen_t[char_t]) {
                return false;
            }
            last_seen_s[char_s] = i + 1;
            last_seen_t[char_t] = i + 1;
        }
        return true;
    }
};