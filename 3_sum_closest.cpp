    int threeSumClosest(vector<int> &num, int target) {
        int distance = INT_MAX;
        int result = INT_MAX;
        for(int i=0; i<num.size()-2; i++) {
            for(int j=i+1; j<num.size()-1; j++) {
                for(int k=j+1; k<num.size(); k++) {
                    int sum = num[i]+num[j]+num[k];
                    if(abs(target - sum) < abs(distance)) {
                        distance = sum - target;
                        result = sum;
                    }
                    if(distance==0) return result;
                }
            }
        }
        return result;
    }
