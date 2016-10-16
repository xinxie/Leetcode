/* Problem: Compare Version Numbers.
 * This solution uses "stringstream" to extract a int from string in a loop operation.
 */

class Solution {
public:
    int compareVersion(string version1, string version2) {
    stringstream ss1(version1),ss2(version2);
    while(ss1 || ss2) {
        char dot;
        int v1=0,v2=0;//IT'S IMPORTANT TO INITIALIZE V1 AND V2.
        if(ss1) ss1>>v1>>dot;
        if(ss2) ss2>>v2>>dot;
        if(v1!=v2) {
            return v1<v2? -1:1;
        }
    }
    return 0;
    }
};