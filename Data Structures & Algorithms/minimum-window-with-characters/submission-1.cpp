class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }
        int resLen = INT_MAX, resStartIndex = -1; 
        int have = 0;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && countT[c] == window[c]) {
                have++;
            }

            while (have == countT.size()) {
                if (r - l + 1 < resLen) {
                    resLen = r - l + 1;
                    resStartIndex = l;
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(resStartIndex, resLen);
    }
};
