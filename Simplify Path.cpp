/* Problem:Simplify Path
   Using vector to control path operation.
 */
class Solution {
public:
    string simplifyPath(string path) {
        string res,curr;
        vector<string>simPath;
        path.push_back('/'); //VERY IMPORTANT. In case of the path name didn't end with '/'
        for(int i=0;i<path.length();i++) {
            if(path[i]=='/') {
                if(curr.empty()) continue;
                if(curr == ".") {
                    curr.clear();
                } else if(curr == "..") {
                    if(!simPath.empty()) simPath.pop_back();
                    curr.clear();
                } else {
                    simPath.push_back(curr);
                    curr.clear();
                }
            } else {
                curr+=path[i];
            }
        }

        for(int i=0;i<simPath.size();i++) {
            res.append('/'+simPath[i]);
        }
        if(simPath.empty()) res="/";
        return res;

    }
};
