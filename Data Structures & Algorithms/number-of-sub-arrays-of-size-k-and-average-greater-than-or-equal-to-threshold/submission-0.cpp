class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0, r = k - 1;

        int res = 0;
        while (r < arr.size()) {
            int sum = 0;
            for (int i = l; i <= r; i++) {
                sum += arr[i];
            }

            if (sum/k >= threshold) res++;

            r++;
            l++;
        }

        return res;
    }
};