int minCut(string s) {
    int n = s.size();
    int *cost = new int[n+1];
    for(int i=0; i<=n; i++) {
        cost[i]=n-i-1;
    }
    int **p = new int*[n];
    for(int i=0; i<n; i++) {
        p[i] = new int[n];
    }
    for(int i=0; i<s.size(); i++) {
        for(int j=0; j<s.size(); j++) {
            p[i][j] = INT_MAX;
        }
    }
    
    for(int i=0; i<s.size(); i++) {
        p[i][i]=1;
    }
    for(int i=0; i+1<s.size(); i++) {
        if(s[i]==s[i+1]) p[i][i+1]=1;
    }
    for(int len=3; len<=s.size(); len++) {
        for(int i=0, j=i+len-1; j<s.size(); i++, j++) {
            if(p[i+1][j-1]!=INT_MAX && s[i]==s[j]) {
                p[i][j]=1;
            }
        }
    }

    for(int i=s.size()-1; i>=0; i--) {
        for(int j=i; j<s.size(); j++) {
            if(p[i][j]==1) {
                cost[i] = min(cost[i], 1+cost[j+1]);
            }
        }
    }
    return cost[0];
}

