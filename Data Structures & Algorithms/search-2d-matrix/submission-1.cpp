class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (vector<int> row : matrix) {
            if (row[row.size() - 1] < target) {
                continue;
            }

            int l = 0, r = row.size() - 1;

            while (l <= r) {
                int mid = l + ((r - l) / 2);

                if (target < row[mid]) {
                    r = mid - 1;
                } else if (target > row[mid]) {
                    l = mid + 1;
                } else {
                    return true;
                }
            }
        }

        return false;
    }
};
