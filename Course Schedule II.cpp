/*
 * Problem: Course Schedule II
 */


// BFS
class Solution {
private:
    vector<unordered_set<int>> make_graph(int n,vector<pair<int, int>>& p) {
        vector<unordered_set<int>> res(n);
        for(auto pair : p) {
            res[pair.second].insert(pair.first);
        }
        return res;
    }

    vector<int> computeIndegrees(vector<unordered_set<int>>& graph, int n) {
        vector<int> res(n, 0);
        for(auto vertex : graph) {
            for(auto neighbor: vertex) {
                res[neighbor]++;
            }
        }
        return res;
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(graph, numCourses);
        queue<int> q;

        for(int i = 0; i < numCourses; ++i) {
            if(!degrees[i]) q.push(i);

        }
        vector<int> res;
        for(int i = 0; i < numCourses; ++i) {
            if(q.empty()) return {};
            int visit = q.front();
            q.pop();
            res.push_back(visit);
            for(auto neighbor : graph[visit]) {
                if(!--degrees[neighbor]) {
                    q.push(neighbor);
                }
            }
        }
        return res;
    }
};


// DFS
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> toposort;
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfs(graph, i, onpath, visited, toposort)) {
                return {};
            }
        }
        reverse(toposort.begin(), toposort.end());
        return toposort;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites) graph[pre.second].insert(pre.first);
        return graph;
    }


    // dfs == true indicates graph is cyclic.
    // dfs == false indicates there is nothing wrong.
    // 因为onpath和visited初始值为false, 如果当dfs返回值为true时表明正常时，在unmark每个
    // 节点为false之后，则使得函数总是return {}。
    bool dfs(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) {
        if (visited[node]) return false;
        onpath[node] = visited[node] = true;
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
                return true;
        toposort.push_back(node);
        return onpath[node] = false;
    }
};
