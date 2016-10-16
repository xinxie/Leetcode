/*Problem: Remove Element
 * This solution is in-place.Complexity O(N);
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        bool flag;
        for(int i = 0; i<nums.size();i++) {
            if(nums[i]!=val) {
                nums[count++]=nums[i];
            }
            flag = true;
        }

        if(flag) {
            for(int i = 0 ; i < nums.size()-count;i++) {
                nums.pop_back();
            }
        }
        return count;
    }
};
