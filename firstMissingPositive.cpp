int firstMissingPositive(int A[], int n) {
    for(int i=0; i<n ;i++) {
        int j=i;
        while (A[j]>0&&A[j]<=n&&A[j]!=j+1&&A[A[j]-1]!=A[j]) {
            swap(A[j], A[A[j]-1]);
        }
    }
    for(int i=0; i<n; i++) {
        if(A[i]!=i+1) return i+1;
    }
    return n+1;
}
