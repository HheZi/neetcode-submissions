class Solution {
   public:
    string longestPalindrome(string s) {
        int longest = 0;
        int longestL = 0, longestR = 0;

        const vector<int> arr = {0, 1};
        
        for (int i = 0; i < s.size(); i++) {
            for (int j : arr) {
                int l = i, r = i + j;
                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    if (r - l + 1 > longest) {
                        longest = r - l + 1;
                        longestL = l;
                        longestR = r;
                    }
                    l--;
                    r++;
                }
            }
        }
        return s.substr(longestL, longestR - longestL + 1);
    }
};
