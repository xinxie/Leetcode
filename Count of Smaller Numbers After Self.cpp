// Problem: Count of Smaller Numbers After Self

// Binary Indexed Tree
class Solution {
private:

    // copy[i] maps bits[i+1].
    // bits[i] array stores the number of element which is >= than copy[i]
    vector<int> bits;

    inline int lowerbit(int i) {
        return i&(-i);
    }

    int query(int pos) {
        int sum = 0;
        while(pos > 0) {
            sum += bits[pos];
            pos -= lowerbit(pos);
        }
        return sum;
    }

    void add(int pos, int val) {
        while(pos < bits.size()) {
            bits[pos] += val;
            pos += lowerbit(pos);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> copy = nums;
        unordered_map<int, int> map;
        int len = nums.size();
        bits.resize(len+1);
        sort(copy.begin(), copy.end());

        for(int i = 0; i < copy.size(); ++i) {
            map[copy[i]] = i+1;
        }

        for(int i = len-1; i>=0; --i) {
            copy[i] = query(map[nums[i]]-1);
            add(map[nums[i]], 1);
        }
        return copy;
    }
};
