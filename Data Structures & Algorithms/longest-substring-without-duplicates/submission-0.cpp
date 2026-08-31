class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set {};
        int length = 0, l = 0;

        for(int r = 0; r < s.length(); r++) {
            while (set.contains(s[r])) {
                set.erase(s[l++]);
            }
            
            set.insert(s[r]);
            length = max(length, r - l + 1);
        }

        return length;
    }
};
