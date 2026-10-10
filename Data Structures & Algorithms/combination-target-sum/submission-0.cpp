class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subSets;
        vector<int> currSet;
        helper(0, subSets, currSet, nums, target, 0);
        return subSets;
    }

        void helper(
        int i, vector<vector<int>> &subSets, 
        vector<int> &currSet, vector<int>& nums,
        int target, int sum
    ) {
        if (sum == target) {
            subSets.push_back(vector<int>(currSet));
            return;
        }

        int n = nums.size();

        if (i > n || sum > target) return;

        for (int j = i; j < n; j++) {
            currSet.push_back(nums[j]);
            sum += nums[j];
            helper(j, subSets, currSet, nums, target, sum);
            sum -= currSet.back();
            currSet.pop_back();
        }
    }
};
