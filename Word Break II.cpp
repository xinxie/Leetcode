
// 9 ms solution
class Solution {
private:
    bool isBreak(string s, unordered_set<string>& wordDict) {
        if(s.length()==0) return false;
        vector<bool>dp(s.length()+1,false);
        dp[0]=true;
        for(int i = 0; i <= s.length();i++) {
            for(int j = i-1; j>=0; j--) {  //looking back is more efficient than start from index 0;
                if(dp[j]) {
                    string word = s.substr(j,i-j);
                    if(wordDict.find(word) != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }

    void wordBreakHelper(string s, unordered_set<string>& wordDict, string chosen,vector<string>& results) {
        if(s.length() == 0) {
            chosen.erase(chosen.length()-1);
            results.push_back(chosen);
        } else {
            for(int i = 1; i <= s.length(); i++) {
                string word = s.substr(0,i);
                if(wordDict.find(word)!=wordDict.end()) {
                    s.erase(0,i);
                    chosen = chosen + word + " ";
                    wordBreakHelper(s,wordDict,chosen,results);
                    s.insert(0,word);
                    chosen.erase(chosen.length()-word.length()-1,word.length()+1);
                }
            }
        }
    }



public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> results;
        if(isBreak(s, wordDict)) wordBreakHelper(s,wordDict,"",results);
        return results;
    }
};




// 13 ms solution
class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
};
