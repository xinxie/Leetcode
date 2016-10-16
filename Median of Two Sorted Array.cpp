class Solution {
public:
    double findKth(vector<int>& A, vector<int>& B, int as, int bs, int k) {
        // 边界情况，任一数列为空
        if (as >= A.size()) {
            return B[bs + k - 1];
        }
        if (bs >= B.size()) {
            return A[as + k - 1];
        }
        // k等于1时表示取最小值，直接返回min
        if (k == 1) return min(A[as], B[bs]);
        int A_key = as + k / 2 - 1 >= A.size() ? INT_MAX : A[as + k / 2 - 1];
        int B_key = bs + k / 2 - 1 >= B.size() ? INT_MAX : B[bs + k / 2 - 1];
        if (A_key < B_key){
            return findKth(A, B, as + k/2, bs, k - k/2);
        } else {
            return findKth(A, B, as, bs + k/2, k - k/2);
        }

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        double ret;

        if (sum & 1) {
            ret = findKth(nums1, nums2, 0, 0, sum/2 + 1);
        } else {
            ret = ((findKth(nums1, nums2, 0, 0, sum/2)) + findKth(nums1, nums2, 0, 0, sum/2 + 1)) / 2.0;
        }
        return ret;
    }
};
