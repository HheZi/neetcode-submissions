class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> subSets;
        vector<int> currSet;
        helper(1, subSets, currSet, n, k);
        return subSets;
    }

    void helper(
        int i, vector<vector<int>> &subSets, 
        vector<int> &currSet, int &n, int &k
    ) {
        if (currSet.size() == k) {
            subSets.push_back(vector<int>(currSet));
            return;
        }

        if (i > n) return;

        for (int j = i; j < n + 1; j++) {
            currSet.push_back(j);
            helper(j + 1, subSets, currSet, n, k);
            currSet.pop_back();
        }
    }
};