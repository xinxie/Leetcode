/*
 * Problem: Clone Graph
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


// BFS
class Solution {
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
    queue<UndirectedGraphNode*> q;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        map[node] = copy;
        q.push(node);

        while(!q.empty()) {
            auto tmp = q.front();
            q.pop();
            for(auto neighbor : tmp->neighbors) {
                if(map.find(neighbor) == map.end()) {
                    UndirectedGraphNode* node = new UndirectedGraphNode(neighbor->label);
                    q.push(neighbor);
                    map[neighbor] = node;
                }
                map[tmp]->neighbors.push_back(map[neighbor]);
            }
        }
        return copy;
    }
};


// DFS
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        if (mp.find(node) == mp.end()) {
            mp[node] = new UndirectedGraphNode(node -> label);
            for (UndirectedGraphNode* neigh : node -> neighbors)
                mp[node] -> neighbors.push_back(cloneGraph(neigh));
        }
        return mp[node];
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
};
