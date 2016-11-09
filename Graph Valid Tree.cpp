// Union-Find
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> root(n);
        for(int i = 0; i < n; ++i) root[i] = i;

        for(const auto& edge : edges) {
            int x = edge.first;
            int y = edge.second;

            while(x != root[x]) x= root[x];
            while(y != root[y]) y = root[y];

            if(x == y) return false;
            root[x] = y;
        }
        return edges.size() == n - 1;
    }
};



// DFS
class Solution {
private:
    vector<unordered_set<int>> make_graph(int n , vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> res(n);
        for(const auto& edge : edges) {
            res[edge.first].insert(edge.second);
            res[edge.second].insert(edge.first);
        }
        return res;
    }

    bool dfs(vector<unordered_set<int>>& graph, vector<int>& visited, int curr, int prev) {

        visited[curr] = 1;

        for(auto neighbor : graph[curr]) {

            // cannot go back to previous node
            if(neighbor == prev) continue;
            if(visited[neighbor] || dfs(graph, visited, neighbor, curr)) {
                return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> graph = make_graph(n, edges);
        vector<int>visited(n,0);

        if(dfs(graph, visited, 0, -1)) return false;

        for(auto num : visited) {
            if(num == 0) return false;
        }
        return true;
    }
};
