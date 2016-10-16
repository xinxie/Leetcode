/*
 * Problem: Range Sum Query – Mutable
 */

// Segment Tree
class NumArray {
private:
    vector<int> tree;
    int n;
public:
    // Bottom-up
    NumArray(vector<int> &nums) {
        n = nums.size();
        tree = vector<int> (2*n);
        for(int i = n, j = 0; i < 2 * n; ++i, ++j) tree[i] = nums[j];
        for(int i = n - 1; i > 0; --i) tree[i] = tree[2*i] + tree[2*i+1];
    }

    void update(int i, int val) {
        i += n;
        tree[i] = val;
        while(i > 0) {
            int left = i, right = i;
            if(i%2 == 0) right = i + 1;
            else left = i - 1;
            tree[i/2] = tree[left] + tree[right];
            i /= 2;
        }

    }

    int sumRange(int i, int j) {
        i += n; // get the position of left bound
        j += n; // get the position of right bound

        int sum = 0;
        while(i <= j) {
            if(i%2 == 1) { // left is out bound
                sum += tree[i];
                i++;
            }

            if(j%2 == 0) { // right is out bound
                sum += tree[j];
                j--;
            }
            i/=2;
            j/=2;
        }
        return sum;
    }
};



// Binary Indexed Tree
class NumArray {
private:
    vector<int> _nums;
    vector<int> bit;

    int lower_bit(int i){
        return i&-i;
    }

    int query(int i){
        i++;
        int sum=0;
        while(i>0){
            sum+=bit[i];
            i-=lower_bit(i);
        }
        return sum;
    }

    void add(int i, int val){
        i++;

        // Notice: "i" cannot be euqal to the bit.size(). Otherwise, throw outbound exception.
        while(i < bit.size()){
            bit[i]+=val;
            i+=lower_bit(i);
        }
    }

public:
    NumArray(vector<int> &nums) : _nums(nums) {
        bit.resize(nums.size()+1);
        for(int i=0; i<nums.size(); i++) {
            add(i, nums[i]);
        }
    }

    void update(int i, int val) {
        if(val!=_nums[i]){
            add(i, val-_nums[i]);
            _nums[i]=val;
        }
    }

    int sumRange(int i, int j) {
        return query(j)-query(i-1);
    }
};
