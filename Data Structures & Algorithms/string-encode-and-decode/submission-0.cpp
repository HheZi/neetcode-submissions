class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string res = to_string(strs.size());

        for (string str : strs) {
            res += ",";

            res += to_string(str.length()); 
        }

        res += ";";
        
        for (string str : strs) {
            res += str; 
        }

        return res;
    }

    vector<string> decode(string s) {
        if(s == "") {
            return {};
        }

        int size  = stoi(s.substr(0, s.find(",")));
        vector<string> res (size);

        int str_offset = s.find(";") + 1;
        int size_offset = s.find(",") + 1;
        for (int i = 0; i < size; i++) {
            int next_size_offset = s.find(",", size_offset);

            int size  = stoi(s.substr(size_offset, next_size_offset - size_offset));

            res[i] = s.substr(str_offset, size);

            size_offset = next_size_offset + 1;
            str_offset += size;
        }

        return res;
    }
};
