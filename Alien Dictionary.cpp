class Solution {
private:
    unordered_map<char, unordered_set<char>> graph;


    // outer loop
    string toposort() {
        unordered_set<char> visited, onpath;
        string order;
        for(auto itr = graph.begin(); itr != graph.end(); ++itr) {
            if(dfs(visited, onpath, order, itr->first) == false) {
                return "";
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }

    // inner dfs
    bool dfs(unordered_set<char>& visited, unordered_set<char>& onpath, string& order, char key) {
        if(visited.count(key)) return true;
        visited.insert(key);
        onpath.insert(key);
        for(auto itr = graph[key].begin(); itr != graph[key].end(); ++itr) {
            if(onpath.count(*itr) || dfs(visited, onpath, order, *itr) == false) { // check cyclic
                return false;
            }
        }
        onpath.erase(key);
        order += key;
        return true;
    }

public:
    string alienOrder(vector<string>& words) {
        if(words.size() == 1) return words[0];
        for(int i = 1; i < words.size(); ++i) {
            string word1 = words[i-1], word2 = words[i];
            bool found = false;
            if(word1.length() > word2.length() && word1.find(word2) == 0) return "";
            for(int j = 0; j < max(word1.length(), word2.length()); ++j) {
                if(j<word1.length() && graph.count(word1[j]) == 0) graph[word1[j]];
                if(j<word2.length() && graph.count(word2[j]) == 0) graph[word2[j]];
                if(j < word1.length() && j < word2.length() && word1[j] != word2[j] && !found) {
                    graph[word1[j]].insert(word2[j]);
                    found = true;
                }
            }
        }
        return toposort();
    }
};
