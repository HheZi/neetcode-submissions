class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int res = 0;

        int l = 0, maxF = 0;
        for(int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            maxF = max(maxF, count[s[r] - 'A']);

            while ((r - l + 1) - maxF > k) {
                count[s[l++] - 'A']--;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
