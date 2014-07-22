    int trap(int A[], int n) {
        if (n<=2) return 0;
        int sum = 0;
        stack<pair<int,int>> s;
        int i=0;
        while(A[i]==0){
            i++;
        }
        for( ; i<n; i++) {
            if(i+1<n && A[i]<=A[i+1]) continue;
            else break;
        }
        if(i<n) { 
            s.push(make_pair(A[i], i)); i++;
        }else { 
            return 0;
        }
        int bar = 0;
        for( ; i<n; i++) {
            if(s.empty()) {
                return 0;
            }
            if(A[i]<s.top().first) {
                s.push(make_pair(A[i], i));
            }else if(A[i]==s.top().first){
                s.top().second = i;
            }else{
                bar = s.top().first; s.pop();
                
                int height = (A[i] > s.top().first) ? s.top().first-bar : A[i]-bar;
                int len = i - s.top().second -1;
                sum += height*len;
                while(!s.empty()&& A[i]>=s.top().first) {
                    bar = s.top().first; s.pop();
                    if(s.empty()) {
                        s.push(make_pair(A[i], i)); break;
                    }else {
                        int height = (A[i] > s.top().first) ? s.top().first-bar : A[i]-bar;
                        int len = i-s.top().second -1;
                        sum += height*len;
                    }
                }
                s.push(make_pair(A[i], i));

            }
        }
        return sum;
        
    }
