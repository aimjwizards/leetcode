    int find(vector<int> &num, int start, int end, int target) {
        if(start>end) return -1;
        int mid = (start+end)/2;
        if(num[mid]==target) return mid;
        if(num[mid]>target) return find(num, start, mid-1, target);
        else return find(num, mid+1, end, target);
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> result;
        if(num.size()<=2) return result;
        std::sort(num.begin(), num.end());
        for(int i=0; i<num.size()-2; i++) {
            if(i>0 && num[i-1]==num[i]) continue;
            for(int j=i+1; j<num.size()-1; j++) {
                if(j>i+1&&num[j-1]==num[j]) continue;
                int partial = num[i]+num[j];
                if(partial>0) break;
                int idx = find(num, j+1, num.size()-1, -partial);
                if(idx==-1) continue;
                vector<int> row;
                row.push_back(num[i]);
                row.push_back(num[j]);
                row.push_back(num[idx]);
                result.push_back(row);
            }
        }
        return result;
    }
