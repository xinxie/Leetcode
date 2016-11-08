#include <vector>
#include <iostream>


using namespace std;


void print(vector<int>& table) {
    for (auto num : table) cout << num << " ";
    cout << endl;
}


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


int KMPAlgorithm(const string& s, const string& p, const vector<int>& table) {
    int n = s.length();
    int m = 0; // the begining of the current match in S
    int i = 0; // the position of the current character in P
    while(m+i < n) {
        if (p[i] == s[m+i]) {
            if (i == p.length()-1) return m; // found matching
            i++;
        } else {
            if(table[i] != -1) {
                m = m + i - table[i];
                i = table[i];
            } else {
                m++;
                i = 0;
            }
        }
    }
    return n;
}

int main() {
    string p = "abcdabd";
    string s = "aldksjfa;adsfabcdabdadsasdfa";
    vector<int> v(p.length(), 0);
    generateTable(p, v);
    print(v);
    cout << "found at: :" << KMPAlgorithm(s, p, v) << endl;
}
