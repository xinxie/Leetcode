void Partition(vector<int>& A, int s, int e) {
    int pivot = A[e], idx = s;
    for(int i = s; i < e; ++i) {
        if(A[i] <= pivot) swap(A[idx++], A[i]);
    }
    swap(A[e], A[idx]);
}
