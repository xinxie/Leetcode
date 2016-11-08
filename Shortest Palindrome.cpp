class Solution {
private:
    void generateTable(const string& p, vector<int>& table) {
        int n = p.length();
        int i = 2, k = 0;
        table[0] = -1; table[1] = 0;
        while(i < n) {
            if(p[i-1] == p[k]) {
                table[i] = k + 1;
                k++;
                i++;
            } else if(k > 0){
                table[i] = 0;
                k = table[k];
            } else {
                table[i] = 0;
                i++;
            }
    }
}
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;
        vector<int> p(l.size(), 0);
        generateTable(l, p);
        return rev_s.substr(0, s.size() - p[l.size() - 1]-1) + s;
    }
};
