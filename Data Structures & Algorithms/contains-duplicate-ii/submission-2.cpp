class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set {};

        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (i - j > k) {
                set.erase(nums[j]);
                j++;
            } 
            
            if (set.contains(nums[i])) {
                return true;
            }

            set.insert(nums[i]);
        }

        return false;
    }
};