class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,  vector<string>> map {};

        for(string &str : strs) {
            vector<int> vec (26, 0);

            for (char &c : str) {
                vec[c - 'a']++;
            }

            string key;
            for(int i : vec) {
                key += "#" + to_string(i);
            }

            map[key].push_back(str);
        }

        vector<vector<string>> res{};

        for (auto & [key, value] : map) {
            res.push_back(value);
        }

        return res;
    }
};
