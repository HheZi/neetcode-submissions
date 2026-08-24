class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;

        int low_val = nums[0];
        while (low <= high) {
            int mid = low + ((high - low) / 2);

            if (nums[low] <= nums[mid] && nums[mid] <= nums[high]) {
                high = mid - 1;
            } else if (nums[low] <= nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

            low_val = min(low_val, nums[mid]);
        }

        return low_val;
    }
};
