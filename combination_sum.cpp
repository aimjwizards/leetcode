    int binarySearch(vector<int> &candidates, int target, int left) {
        int right = candidates.size()-1;
        int mid = 0;
        while(left<=right) {
            mid = (left+right)/2;
            if(target==candidates[mid]) {
                return mid;
            }else if(target<candidates[mid]) {
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return -1;
    }

    void helper(vector<int> &candidates, int target, vector<vector<int>>&result, vector<int> &row, int small_idx) {
        if(target<candidates[0]) return;

        int idx = binarySearch(candidates, target, small_idx);
        if(idx!=-1) {
            row.push_back(candidates[idx]);
            result.push_back(row);
            row.pop_back();
        }
        
        for(int i=small_idx; i<candidates.size(); i++) {
            int new_target = target-candidates[i];
            row.push_back(candidates[i]);
            helper(candidates, new_target, result, row, i);
            row.pop_back();
        }
        
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size()<1) return result;
        sort(candidates.begin(), candidates.end());
        vector<int> row;
        int small_idx=0;
        helper(candidates, target, result, row, small_idx);
        return result;
    }
