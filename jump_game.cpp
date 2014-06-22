
    bool canJump(int A[], int n) {
        int canReach = 0;
        for(int i=0; i<n&&i<=canReach; i++) {
            if(i+A[i]>canReach) canReach = i+A[i];
            if(canReach >=n-1) return true;
        }
        return canReach >= n-1;
    }
