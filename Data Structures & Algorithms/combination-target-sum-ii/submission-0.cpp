class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> subSets;
        vector<int> currSet;
        helper(0, subSets, currSet, candidates, target, 0);
        return subSets;
    }

    void helper(int i, vector<vector<int>>& subSets, vector<int>& currSet, vector<int>& nums,
                int target, int sum) {
        if (sum == target) {
            subSets.push_back(vector<int>(currSet));
            return;
        }

        if (sum > target || i == nums.size()) {
            return;
        }

        currSet.push_back(nums[i]);
        helper(i + 1, subSets, currSet, nums, target, sum + nums[i]);
        currSet.pop_back();

        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        helper(i + 1, subSets, currSet, nums, target, sum);
    }
};
