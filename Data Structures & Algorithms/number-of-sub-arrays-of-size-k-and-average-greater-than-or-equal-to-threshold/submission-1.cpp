class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        for (int i = 0; i < k - 1; i++) {
            sum += arr[i];
        }

        int res = 0;
        for(int i = k - 1; i < arr.size(); i++) {
            sum += arr[i];

            if (sum/k >= threshold) res++;

            sum -= arr[i - (k - 1)];
        }

        return res;
    }
};