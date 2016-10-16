/*Problem: Rotate Array 
 *This solution uses in-place rotation method.
 *The trick is to do three reverse operation. One for the entire string,
 *one from index 0 to k-1, and lastly index k to n-1.
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();//VERY IMPORTANT. Deal with cases when k is larger than num.size().
        if(nums.size()==0) return;
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }

private:
    void reverse(vector<int>& nums, int start, int end){
        while(start<end) {
            swap(nums[start],nums[end]);
            start++,end--;
        }
    }
};
