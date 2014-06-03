    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size()==0) return 0;
        // build table
        int row = matrix.size(); int col = matrix[0].size();
        vector<vector<int>> table(row, vector<int>(col, 0));
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                int count = 0;
                for(int k=j; k<col; k++) {
                    if(matrix[i][k]=='1') {
                        count++;
                    }else{
                        break;
                    }
                }
                table[i][j] = count;
            }
        }
        int max_area=0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(table[i][j]==0) continue;
                int width=table[i][j];
                int up = i;
                while((up-1)>=0&&table[up-1][j]>=width) {
                    up--;
                }
                int down = i;
                while((down+1)<row&&table[down+1][j]>=width) {
                    down++;
                }
                int height = down-up+1;
                max_area = max(max_area, height*width);
            }
        }
        return max_area;
    }
