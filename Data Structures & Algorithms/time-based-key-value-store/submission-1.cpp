class TimeMap {
private:
    map<string, set<pair<int, string>>> map {};
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        map[key].insert(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if (map.find(key) == map.end()) {
            return "";
        }
        
        auto& values = map[key];
        auto it = values.lower_bound({timestamp + 1, ""});

        if (it != values.begin()) {
            it--;
            return it->second;
        }

        return "";
    }
};
