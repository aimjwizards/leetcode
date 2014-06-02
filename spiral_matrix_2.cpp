class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, INT_MIN));
        int left=0, right=n-1, top=0, bottom=n-1;
        int k=1;
        for(int len=0; len<n/2; len++) {
            for(int i=len; i<right; i++) {
                result[top][i] = k++;
            }
            for(int j=len; j<bottom; j++) {
                result[j][right] = k++;
            }
            for(int i=right; i>len; i--) {
                result[bottom][i] = k++;
            }
            for(int j=bottom; j>len; j--) {
                result[j][left] = k++;
            }
            left++; right--; top++; bottom--;
        }
        if(n%2){
            result[n/2][n/2] = k;
        }
        return result;
    }
};
