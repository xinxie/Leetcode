class Solution {
class TrieNode {
public:
    TrieNode* next[26];
    vector<string> prefixWords;
    TrieNode() {
        memset(next, 0, sizeof(next));
        prefixWords = vector<string>();
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie (vector<string>& words) {
        root = new TrieNode();
        for(auto word : words) {
            auto curr = root;
            for(int i = 0; i < word.length(); ++i) {
                auto tmp = curr->next[word[i]-'a'];
                if(!tmp) curr->next[word[i]-'a'] = new TrieNode();
                (curr->next[word[i]-'a']->prefixWords).push_back(word);
                curr = curr->next[word[i]-'a'];
            }
        }
    }

    vector<string> findPrefix(string pre) {
        vector<string> res;
        auto curr = root;
        for(auto ch : pre) {
            if(curr->next[ch-'a'] == NULL) return res;
            curr = curr->next[ch-'a'];
        }
       // cout << (curr->prefixWords).size() << endl;
        return curr->prefixWords;
        //res.emplace_back(curr->prefixWords);
        // return res;
    }
};

private:
    vector<vector<string>> res;
    vector<string> chosen;

    void helper(Trie& trie, int n) {
        if(chosen.size() == n) {
            res.push_back(chosen);
            return;
        }

        int idx = chosen.size();
        string build = "";

        for(auto& word:chosen) build += word[idx];
        vector<string> candidates = trie.findPrefix(build);
        for(auto candidate : candidates) {
            chosen.push_back(candidate);
            helper(trie, n);
            chosen.pop_back();
        }
    }

public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        if(words.empty()) return res;

        Trie trie(words);
        for(auto word : words) {
            chosen.push_back(word);
            helper(trie, words[0].length());
            chosen.pop_back();
        }
        return res;
    }
};
