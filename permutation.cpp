    void helper(vector<int> &num, vector<vector<int>>&results, int start) {
        if(start==num.size()) {
            results.push_back(num);
            return;
        }
        for(int i=start; i<num.size(); i++) {
            swap(num[start], num[i]);
            helper(num, results, start+1);
            swap(num[start], num[i]);
        }
        
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> results;
        if(num.size()==0) return results;
        helper(num, results, 0);
        return results;
    }
