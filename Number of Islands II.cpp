class Solution {
private:
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<int> root;

    int getRoot(int idx) {
        while(idx != root[idx]) {
            root[idx] = root[root[idx]]; // path compression
            idx = root[idx];
        }
        return idx;
    }

public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        root = vector<int> (m*n, -1);
        int island = 0;

        for(auto pos:positions) {
            int currX = pos.first, currY = pos.second;
            int idx = currX*n+currY;
            root[idx] = idx;
            ++island;
            for(auto d:dir) {
                int x = currX+d[0], y = currY+d[1], id = x*n+y;
                if(x<0 || x>= m || y<0 || y>=n || root[id] == -1) continue;
                int currRoot = getRoot(idx), xyRoot = getRoot(id);
                if(currRoot != xyRoot) {
                    root[xyRoot] = currRoot;
                    --island;
                }
            }
            res.push_back(island);
        }
        return res;
    }
};
