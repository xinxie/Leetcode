// Binary Indexed Tree
class NumMatrix {
private:
    vector<vector<int>> nums;
    vector<vector<int>> bit;
    int rows;
    int cols;

    void add(int m, int n, int val) {
        m++; n++;
        while(m <= rows) {
            int colId = n;
            while(colId <= cols) {
                bit[m][colId] += val;
                colId += (colId & (-colId));
            }
            m += (m&(-m));
        }
    }

    int region(int m, int n) {
        m++;n++;
        int sum = 0;
        while(m > 0) {
            int colIdx = n;
            while(colIdx > 0) {
                sum +=  bit[m][colIdx];
                colIdx -= (colIdx & (-colIdx));
            }
            m -= (m&(-m));
        }
        return sum;
    }


public:
    NumMatrix(vector<vector<int>> &matrix) : nums(matrix)  {
        if(!matrix.size() || !matrix[0].size()) return;
        rows = matrix.size();
        cols = matrix[0].size();
        bit = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                add(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int diff = val - nums[row][col];
        add(row, col, diff);
        nums[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = 0, b = 0, c = 0, d = 0;

        d = region(row2, col2);
        if(row1 > 0 && col1 > 0) a = region(row1 - 1, col1 - 1);
        if(col1 > 0) b = region(row2, col1 - 1);
        if(row1 > 0) c = region(row1 - 1, col2);
        return d - b - c + a;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
