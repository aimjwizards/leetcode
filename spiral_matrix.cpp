class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        int m=matrix.size(); if(m<1) return result;
        int n=matrix[0].size();
        
        int left=0, right=n-1, top=0, bottom=m-1;
        int step = min(m, n);
        for(int len=0; len<step/2; len++) {
            for(int i=left; i<right; i++) {
                result.push_back(matrix[top][i]);
            }
            for(int j=top; j<bottom; j++) {
                result.push_back(matrix[j][right]);
            }
            for(int i=right; i>left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            for(int j=bottom; j>top; j--) {
                result.push_back(matrix[j][left]);
            }
            left++; right--; top++; bottom--;
        }
        if(step%2) {
            if(m==n){
                result.push_back(matrix[step/2][step/2]);
            }else if(m<n) {
                for(int i=left; i<=right; i++) {
                    result.push_back(matrix[step/2][i]);
                }
            }else {
                for(int j=top; j<=bottom; j++) {
                    result.push_back(matrix[j][step/2]);
                }
            }
        }
        return result;
   }
}; 
