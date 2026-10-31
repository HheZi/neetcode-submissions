class Solution {
   public:
    string longestPalindrome(string s) {
        int longest = 0;
        string res = "";

        const vector<int> arr = {0, 1};

        for (int i = 0; i < s.size(); i++) {
            for (int j : arr) {
                int l = i, r = i + j;
                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    if (r - l + 1 > longest) {
                        longest = r - l + 1;
                        res = s.substr(l, r - l + 1);
                    }
                    l--;
                    r++;
                }
            }
        }
        return res;
    }
};
