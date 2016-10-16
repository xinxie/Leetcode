/* Problem: Restore IP Addresses
 * This program uses DFS to implement searching.
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        dfs(s,0,0,ip,res);
        return res;
    }
    //step is the number of partition we've completed.
    void dfs(string s, int start, int step, string ip, vector<string>& res) {
        if(start == s.size() && step ==4) {
            ip.erase(ip.end()-1); //remove the last char, which is "."
            res.push_back(ip);
            return;
        } else {
            //Make sure the length of each partition should not be too short.
            if(s.size()-start>((4-step)*3)) return;
            //Make sure the length of each partition should not be too long.
            if(s.size()-start<(4-step)) return;
            int num = 0;
            for(int i= start; i<start+3;i++) {
                num = num*10 + (s[i]-'0');
                if(num<=255) {
                    ip+=s[i];
                    dfs(s,i+1,step+1,ip+".",res); //pick one and explore
                }
                if(num==0) break;
            }

        }
    }
};
