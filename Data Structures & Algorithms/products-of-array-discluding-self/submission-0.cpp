class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res (size), pref (size), suff (size);

        pref[0] = 1;
        suff[size - 1] = 1;
        for (int i = 1; i < size; i++) {
            pref[i] = nums[i - 1] * pref[i - 1];
        }

        for (int i = size - 2; i >= 0; i--) {
            suff[i] = nums[i + 1] * suff[i + 1];
        }

        for (int i = 0; i < size; i++) {
            res[i] = pref[i] * suff[i];
        }

        return res;
    }
};
