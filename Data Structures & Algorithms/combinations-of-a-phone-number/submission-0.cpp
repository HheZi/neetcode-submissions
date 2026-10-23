class Solution {
   private:
    vector<vector<char>> characters{
        {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'},
        {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'},
    };

    void backtracking(vector<string>& res, string& digits, string& curStr, int digitIndex) {
        if (curStr.size() == digits.size()) {
            res.push_back(curStr);
            return;
        }

        int charactersIndex = (digits[digitIndex] - '0') - 2;

        for(int i = 0; i < characters[charactersIndex].size(); i++) {
            curStr.push_back(characters[charactersIndex][i]);
            backtracking(res, digits, curStr, digitIndex + 1);
            curStr.pop_back();
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> res;
        string curStr;
        backtracking(res, digits, curStr, 0);

        return res;
    }
};
