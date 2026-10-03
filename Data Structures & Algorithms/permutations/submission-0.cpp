class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms {{}};

        for (int n : nums) {
            vector<vector<int>> nextPerms;
            for (vector<int> p : perms) {
                for (int i = 0; i < p.size() + 1; i++) {
                    vector<int> copy (p);
                    copy.insert(copy.begin() + i, n);
                    nextPerms.push_back(copy);
                }
            }
            perms = nextPerms;
        }

        return perms;
    }
};
