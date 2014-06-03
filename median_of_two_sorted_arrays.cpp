    double helper(int A[], int m, int B[], int n, int k) {
        
        if(m==0) return B[k-1];
        if(n==0) return A[k-1];
        if(k==1) return min(A[0], B[0]);
        if(A[m/2]<=B[n/2]) {
            if(m/2+n/2+1>=k) {
                return helper(A, m, B, n/2, k);
            }else {
                return helper(A+m/2+1, m-m/2-1, B, n, k-m/2-1);
            }
            
        }else {
            if(m/2+n/2+1>=k) {
                return helper(A, m/2, B, n, k);
            }else {
                return helper(A, m, B+n/2+1, n-n/2-1, k-n/2-1);
            }
        }
        
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        
        if((m+n)%2) {
            return helper(A, m, B, n, (m+n)/2+1);
        }else{
            return 0.5*(helper(A, m, B, n, (m+n)/2+1)+helper(A, m, B, n, (m+n)/2));
        }
    }
