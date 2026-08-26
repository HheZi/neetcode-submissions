class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> map {};
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].emplace_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) {
            return "";
        }
        
        auto &values = map[key];
        
        int low = 0, high = values.size() - 1;
        string result = "";

        while (low <= high) {
            int mid = low + ((high - low) / 2);

            if (values[mid].first == timestamp) {
                return values[mid].second;
            }

            if (values[mid].first <= timestamp) {
                result = values[mid].second;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
