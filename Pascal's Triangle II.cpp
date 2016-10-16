/* Problem: Pascal's Triangle II
 * Solution one is better for its efficiency. Solution is using recursion
 * to calculate each term.
 */


//Solution 1
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res(rowIndex+1,0);
        res[0]=1;
        for(int i = 0; i <= rowIndex; i++) {
            for(int j = i;j>0;j--) {
                res[j]+=res[j-1];
            }
        }
        return res;
    }
};

 //Solution 2
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.resize(rowIndex+1);
        for(int i = 0; i <= rowIndex; i++) {
            res[i]=compute(i,rowIndex);
        }
        return res;

    }

    int compute(int i,int row) {
        if(i==0||i==row) {
            return 1;
        } else {
            return compute(i-1,row-1) + compute(i,row-1);
        }
    }
};
