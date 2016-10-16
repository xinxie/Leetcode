/*
 * Problem: Majority Element II
 */


// Boyer-Moore Majority Vote Algorithm

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;

        int n = nums.size();
        int a = 0, b = 0, count1 = 0, count2 = 0;
        for(auto num: nums) {
            if(num == a) count1++;
            else if(num == b) count2++;
            else if(count1 == 0) {
                a = num;
                count1 = 1;
            } else if(count2 == 0) {
                b = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for(auto num: nums) {
            if(num == a) count1++;
            else if(num == b) count2++;
        }

        if(count1 > n / 3) res.push_back(a);
        if(count2 > n / 3) res.push_back(b);
        return res;
    }
};
