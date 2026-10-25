class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end()), low = 1;
        int res = high;

        while (low <= high) {
            int k = (high + low) / 2;

            long long sum = 0;
            for (int pile : piles) {
                sum += ceil(static_cast<double>(pile) / k);
            }
            if (sum <= h) {
                res = k;
                high = k - 1; 
            } else { 
                low = k + 1; 
            }
        }

        return res;
    }
};
