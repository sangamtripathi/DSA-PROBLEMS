class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int k{};

        for (int i{n - 1}; i >= 0; --i) {
            while (s[i] == ' ' && k == 0) {
                --i;
            }
            if (s[i] != ' ') {
                k++;
            } else {
                break;
            }
        }

        return k;
    }
};