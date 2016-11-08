/**
 * Problem: Generalized Abbreviation
 */

class Solution {
private:
    void helper(vector<string>& res, string word, int pos, string cur, int count) {
        if(pos == word.length()) {
            if(count) cur += to_string(count);
            res.push_back(cur);
        } else {
            helper(res, word, pos+1, cur, count+1); // keep the char
            helper(res, word, pos+1, cur + (count > 0?to_string(count):"")+word[pos], 0); // abbreviate it
        }
    }

public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        helper(res, word, 0, "", 0);
        return res;
    }
};
