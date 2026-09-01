class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())        
            return false;

        vector<int> v1(26, 0), v2(26, 0);
        for (int i = 0; i < s1.length(); i++) {
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (v1[i] == v2[i]) {
                matches++;
            }
        }

        int l = 0;
        for (int r = s1.length(); r < s2.length(); r++) {
            if (matches == 26) {
                return true;
            }

            int index = s2[r] - 'a';
            v2[index]++;
            if (v1[index] == v2[index]) {
                matches++;
            } else if (v1[index] + 1 == v2[index]) {
                matches--;
            }

            index = s2[l] - 'a';
            v2[index]--;
            if (v1[index] == v2[index]) {
                matches++;
            } else if (v1[index] - 1 == v2[index]) {
                matches--;
            }
            l++;
        }
        return matches == 26;
    }
};
