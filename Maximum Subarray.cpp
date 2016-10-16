/*
 * Problem: Maximum Subarray
 */

// O(N) solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int currSum = nums[0], maxSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            currSum = currSum<=0 ? nums[i]:currSum+nums[i];
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};

// Divide and Conquer approach
class Solution {
private:
    int findCrossingSum(vector<int>& nums, int low, int mid, int high) {
        int leftSum = INT_MIN, rightSum = INT_MIN, maxLeft = INT_MIN, maxRight = INT_MIN,sum = 0;
        for(int i = mid; i>= low; i--) {
            sum = sum + nums[i];
            if(sum > leftSum) leftSum = sum;
        }
        sum = 0;
        for(int j = mid+1; j<= high; j++) {
            sum = sum + nums[j];
            if(sum > rightSum) rightSum  = sum;
        }
        return leftSum + rightSum;
    }

    int divideAndConquer(vector<int>& nums, int low, int high) {
        if(high == low) return nums[low];
        int mid = (low+high)/2;

        // Recursive Dividing Array
        int leftSum = divideAndConquer(nums,low,mid);
        int rightSum = divideAndConquer(nums,mid+1,high);

        int cross = findCrossingSum(nums,low,mid,high);

        if(leftSum >= rightSum && leftSum >= cross) return leftSum;
        else if(rightSum >= leftSum && rightSum >= cross) return rightSum;
        else return cross;
    }

public:
    int maxSubArray(vector<int>& nums) {
        return divideAndConquer(nums,0,nums.size()-1);
    }
};
