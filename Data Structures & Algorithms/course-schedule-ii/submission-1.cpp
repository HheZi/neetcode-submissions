class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj (numCourses);
        vector<int> indegree (numCourses, 0);

        for (auto& pre : prerequisites) {
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> res;
        queue<int> nodeQueue;
        while (!q.empty()) {
            nodeQueue.push(q.front());
            q.pop();

            while (!nodeQueue.empty()) {
                int node = nodeQueue.front();
                nodeQueue.pop();

                for (int course : adj[node]) {
                    indegree[course]--;
                    if (indegree[course] == 0) {
                        nodeQueue.push(course);
                    }
                }
                res.push_back(node);
            }
        }

        if (res.size() != numCourses) {
            return {};
        }

        return res;
    }
};
