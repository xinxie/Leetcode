//Merge Sort

class Solution {
private:
    void merge(vector<int>& result, vector<int>& left, vector<int>& right) {
        int i1 = 0, i2 = 0;
        for(int i = 0; i < left.size() + right.size(); ++i) {
            if(i2 >= right.size() || (i1 < left.size() && left[i1] <= right[i2])) {
                result.push_back(left[i1++]);
            } else {
                result.push_back(right[i2++]);
            }
        }
    }
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() >= 2) {
            int size = nums.size();
            vector<int> left = vector<int>(nums.begin(), nums.begin() + size / 2);
            vector<int> right = vector<int>(nums.begin() + size / 2, nums.end());
            sortColors(left);
            sortColors(right);
            nums.clear();
            merge(nums, left, right);
        }
    }
};
