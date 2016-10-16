/*
    Problem: Number of Islands

 */



// DFS
class Solution {
private:
    void DFS(vector<vector<char>>& g, int i, int j) {
        g[i][j] = '0';
        if(i > 0 && g[i-1][j] == '1') DFS(g, i-1, j);
        if(i < g.size() - 1 && g[i+1][j] == '1') DFS(g, i+1, j);
        if(j > 0 && g[i][j-1] == '1') DFS(g, i, j-1);
        if(j < g[0].size() - 1 && g[i][j+1] == '1') DFS(g, i, j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    res++;
                    DFS(grid, i, j);
                }
            }
        }
        return res;
    }
};


// BFS
class Solution {
private:
    void BFS(vector<vector<char>>& g, int i, int j) {
        queue<vector<int>> q;
        vector<int> tmp = {i, j};
        g[i][j] = '0';
        q.push(tmp);
        while(!q.empty()) {
            i = q.front()[0];
            j = q.front()[1];
            q.pop();
            if(i > 0 && g[i-1][j] == '1') {
                q.push({i-1, j});
                g[i-1][j] = '0';
            }
            if(i < g.size() -1 && g[i+1][j] == '1') {
                q.push({i+1,j});
                g[i+1][j] = '0';
            }
            if(j > 0 && g[i][j-1] == '1') {
                q.push({i, j-1});
                g[i][j-1] = '0';
            }
            if(j < g[0].size() - 1 && g[i][j+1] == '1') {
                q.push({i, j+1});
                g[i][j+1] = '0';
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    res++;
                    BFS(grid, i, j);
                }
            }
        }
        return res;
    }
};
