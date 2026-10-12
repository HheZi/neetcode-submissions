class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res(nums.size() - k + 1);
        deque<int> q;


        int l = 0, r = 0;
        while (r < nums.size()) {
            while(!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r);

            if (l > q.front()) {
                q.pop_front();
            }

            if (r >= k - 1) {
                res[l++] = nums[q.front()];
            }
            r++;
        }
        
        return res;
    }
};
