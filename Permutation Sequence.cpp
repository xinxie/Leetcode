/*
 * Problem: Permutation Sequence
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac(n+1); // looking table
        vector<int> id(n); // storing the number which can be used
        fac[0]=1;
        for(int i = 1; i <= n; ++i) fac[i] = i * fac[i-1];
        for(int i = 0; i < n; ++i) id[i] = i+1;

        k--; // delete [1,2,3,4...n]
        string build = "";
        for(int i = 1; i <= n; ++i) {
            int index = k/fac[n-i];
            build += to_string(id[index]);
            id.erase(id.begin() + index);
            k -= index*fac[n-i];
        }
        return build;
    }
};
