class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<double, int>, 
            vector<pair<double, int>>, 
            greater<pair<double, int>>
        > heap;


        for (int i = 0; i < points.size(); i++) {
            double distance = sqrt(
                pow(points[i][0], 2) + pow(points[i][1], 2)
            );

            heap.push({distance, i});
        }

        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            res.emplace_back(points[heap.top().second]);
            heap.pop();
        }
        return res;
    }
};
