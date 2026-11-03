class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        unordered_set<int> visited;

        for (auto& vec : prerequisites) {
            adjList[vec[0]].push_back(vec[1]);
        }

        for (auto& vec : prerequisites) {
            if (!dfs(adjList, visited, vec[0])) {
                return false;
            }
        }

        return true;
    }

    bool dfs(unordered_map<int, vector<int>>& adjList, unordered_set<int>& visited, int val) {
        if (visited.contains(val)) return false;

        visited.insert(val);

        for (int prerequisition : adjList[val]) {
            if (!dfs(adjList, visited, prerequisition)) {
                return false;
            }
        }

        visited.erase(val);
        adjList[val].clear();
        return true;
    }
};
