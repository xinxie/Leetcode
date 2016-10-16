/* Problem: Climbing Stairs.
 * Dynamic Programming
 */
class Solution {
public:
    int climbStairs(int n) {
        if(!n || n == 1 || n == 2) return n;
        int* res = new int[n+1];
        res[1] = 1; // res[n] stores the number of ways to reach the nth stairs. 
        res[2] = 2;
        for(int i = 3; i <= n ; i++) res[i] = res[i-1] + res[i-2];
        return res[n];
    }
};
