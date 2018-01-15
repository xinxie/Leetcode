// This algorithm is used to find the max subarray sum
// in a given array.



int find_max_subarray(const vector<int>& arr) {
    if(arr.size() == 1) return arr[0];
    int max_sum = arr[0], tmp = arr[0];

    for(int i = 1; i < arr.size(); ++i) {
        tmp = max(arr[i], tmp + arr[i]);
        if(tmp > max_sum) max_sum = tmp;
    }

    return max_sum;
}
