/*
 *  Problem: Course Schedule
 */


 // BFS
class Solution {
private:
    vector<unordered_set<int>> make_graph(int n, vector<pair<int, int>>& p) {
        vector<unordered_set<int>> res(n);
        for(auto pair : p) {
            res[pair.second].insert(pair.first);
        }
        return res;
    }

    vector<int> computeIndegree(vector<unordered_set<int>>& graph, int n) {
        vector<int> res(n, 0);
        for(auto vertex : graph) {
            for(auto neighbor : vertex) {
                res[neighbor]++;
            }
        }
        return res;
    }

public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = computeIndegree(graph, numCourses);

        for(int i = 0; i < numCourses; ++i) { // iterate over all nodes
            int j = 0;

            for(; j < numCourses; ++j) { //finding the first non-zero node
                if(degrees[j] == 0) break;
            }

            // Can't find a node with 0 degree. Must be a cycle
            if(j == numCourses) return false;

            degrees[j]--;

            for(auto neighbor : graph[j]) {
                degrees[neighbor]--;
            }
        }
        return true;
    }
};




// DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited)) {
                return false;
            }
        }
        return true;
    }

private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites) graph[pre.second].insert(pre.first);
        return graph;
    }

    bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
        if (visited[node]) return false;
        onpath[node] = visited[node] = true;
        for (int neigh : graph[node]) {
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited)) {
                return true;
            }
        }
        onpath[node] = false;
        return false;
    }
};
