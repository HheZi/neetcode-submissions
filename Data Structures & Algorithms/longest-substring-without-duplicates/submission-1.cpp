class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map {};
        int length = 0, l = 0;

        for(int r = 0; r < s.length(); r++) {
            if (map.contains(s[r])) {
                l = max(map[s[r]] + 1, l);
            }
            
            map[s[r]] = r;
            length = max(length, r - l + 1);
        }

        return length;
    }
};
