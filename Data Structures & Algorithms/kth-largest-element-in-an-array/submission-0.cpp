class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());

        int res = nums[0];
        for (int i = 0; i < k; i++) {
            res = nums.front();

            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return res;
    }
};
