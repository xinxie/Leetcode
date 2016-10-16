/* Digital Root Problem:
 * Digital Root of a non-negative integer is the value obtained by an iterative process
 * of summing digits, on each iteration using the result from the previous iteration to
 * compute a digit sum.
 */
 
 
class Solution {
public:
    int addDigits(int num) {
        if(num <= 0) {
            return 0;
        } else {
            return num-9*((num-1)/9);
        }
    }
}; 
 