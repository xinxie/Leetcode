/*
 * Problem: Minimum Size Subarray
 */


// O(N) solution.
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;

        int start = 0, sum = 0, length = INT_MAX;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while(sum >= s) {
                length = min(length, i - start + 1);
                sum -= nums[start++];
            }
        }
        return length == INT_MAX ? 0 : length;
    }
};



// O(NlogN) solution using upper_bound
class Solution {
private:
    vector<int> computeSums(vector<int>& nums) {
        vector<int> res(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); ++i) {
            res[i] = res[i-1] + nums[i-1];
        }
        return res;
    }
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> sums = computeSums(nums);

        int length = INT_MAX;
        for(int i = 1; i <= sums.size(); ++i) {
            if(sums[i] >= s) {
                vector<int>::iterator itr = upper_bound(sums.begin(), sums.end(), sums[i] - s);
                if(itr != sums.end()) {
                    int pos = itr - sums.begin();
                    length = min(length, i - pos + 1);
                }
            }
        }
        return length == INT_MAX ? 0 : length;
    }
};
