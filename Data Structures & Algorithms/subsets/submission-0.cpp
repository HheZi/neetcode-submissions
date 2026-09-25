class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currSet;
        helper(0, nums, subsets, currSet);
        return subsets;
    }

    void helper(
        int i, vector<int> &nums, 
        vector<vector<int>> &subsets, vector<int> &currSet
    ) {
        if (i >= nums.size()) {
            subsets.push_back(vector<int>(currSet));
            return;
        }

        currSet.push_back(nums[i]);
        helper(i + 1, nums, subsets, currSet);
        currSet.pop_back();

        helper(i + 1, nums, subsets, currSet);
    }
};
