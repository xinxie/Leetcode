class Solution {

class TrieNode {
public:
    TrieNode* next[26];
    bool isword = false;
    // Initialize your data structure here.
    TrieNode() {
        memset(next, 0, sizeof(next)); // set all nullptr
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        auto curr = root;
        for(int i = 0; i < word.size(); ++ i) {
            auto tmp = curr->next[word[i]-'a'];
            if(!tmp) curr->next[word[i]-'a'] = new TrieNode();
            curr = curr->next[word[i]-'a'];
        }
        curr->isword = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        auto tmp = find(word);
        if(tmp && tmp->isword) {
            tmp->isword = false; // avoiding duplicate
            return true;
        } else return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix);
    }

private:
    TrieNode* root;

    TrieNode* find(string key) {
        auto curr = root;
        for(int i = 0; curr && i < key.length(); ++i) {
            curr = curr->next[key[i]-'a'];
        }
        return curr;
    }
};

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(words.empty() || board.empty()) return res;

        int m = board.size(), n = board[0].size();
        for(auto& word:words) trie.insert(word);

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                dfs(board, res, "", i, j, m, n);
            }
        }
        return res;
    }
private:
    Trie trie;

    void dfs(vector<vector<char>>& board, vector<string>& res, string tmpString, int row, int col, int M, int N) {
        char origin = board[row][col];
        string tmp = tmpString + origin;
        if(board[row][col] == '#') return;
        if(!trie.startsWith(tmp)) return;
        board[row][col] = '#';
        if(trie.search(tmp)) res.push_back(tmp);
        if(row>0) dfs(board, res, tmp, row-1, col, M, N);
        if(row < M-1) dfs(board, res, tmp, row+1, col, M, N);
        if(col > 0) dfs(board, res, tmp, row, col-1, M, N);
        if(col < N-1) dfs(board, res, tmp, row, col+1, M, N);
        board[row][col] = origin;
    }
};
