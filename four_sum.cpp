 int find(vector<int> &num, int start, int end, int target) {
        if(start>end) return -1;
        int mid = (start+end)/2;
        if(num[mid]==target) return mid;
        if(num[mid]>target) return find(num, start, mid-1, target);
        else return find(num, mid+1, end, target);
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
           
        vector<vector<int>> result;
        if(num.size()<=3) return result;
        std::sort(num.begin(), num.end());
        for(int i=0; i<num.size()-3; i++) {
            if(i>0 && num[i-1]==num[i]) continue;
            for(int j=i+1; j<num.size()-2; j++) {
                if(j>i+1&&num[j-1]==num[j]) continue;
                for(int k=j+1; k<num.size()-1; k++) {
                    if(k>j+1&&num[k-1]==num[k]) continue;
                    int partial = num[i]+num[j]+num[k];
                    if(partial+num[k+1]>target) break;
                    int idx = find(num, j+1, num.size()-1, target-partial);
                    if(idx==-1) continue;
                    vector<int> row;
                    row.push_back(num[i]);
                    row.push_back(num[j]);
                    row.push_back(num[k]);
                    row.push_back(num[idx]);
                    result.push_back(row);
                }
            }
        }
        return result;
    
    }
