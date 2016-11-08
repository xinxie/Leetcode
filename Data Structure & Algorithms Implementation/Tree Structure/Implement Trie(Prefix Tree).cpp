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
        return tmp && tmp->isword;
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


// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
