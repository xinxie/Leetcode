class Solution {
private:
    vector<vector<int>> dir{{1,0}, {-1,0}, {0,-1}, {0,1}};
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return -1;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cache = grid;

        // step is the signal of each walking
        int step = 0, dis;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    dis = -1;
                    queue<vector<int>> q;
                    q.push({i, j});
                    auto copy = grid;
                    copy[i][j] = 0;

                    while(q.size()) {
                        int curr_x = q.front()[0], curr_y = q.front()[1];
                        q.pop();
                        for(auto d : dir) {
                            int x = curr_x + d[0], y = curr_y + d[1];
                            if(x<0 || x>=m || y<0 || y>=n || grid[x][y] != step) continue;

                            grid[x][y]--; // from 0 to -1, from -1 to -2, and so on.
                            copy[x][y] = copy[curr_x][curr_y]+1;
                            cache[x][y] += copy[x][y];
                            q.push({x, y});
                            if(dis < 0 || cache[x][y] < dis) dis = cache[x][y];
                        }
                    }
                    step--;
                }
            }
        }
        return dis;
    }
};
