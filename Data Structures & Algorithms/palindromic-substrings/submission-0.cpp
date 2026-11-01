class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        const vector<int> arr = {0, 1};
        for (int i = 0; i < s.size(); i++) {
            for (int j : arr) {
                int l = i, r = i + j;
                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    res++;
                    l--;
                    r++;
                }
            }
        }
        return res;
    }
};
