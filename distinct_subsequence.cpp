    int numDistinct(string S, string T) {
        int row = T.size();
        int col = S.size();
        if(row>col) return 0;
        vector<vector<int>>table(row, vector<int>(col, 0));
        if(S[0]==T[0]) table[0][0]=1;
        for(int j=1; j<col; j++) {
            if(S[j]==T[0]) {
                table[0][j] = table[0][j-1]+1;
            }else {
                table[0][j] = table[0][j-1];
            }
        }
        for(int i=1; i<row; i++) {
            for(int j=i; j<col; j++) {
                if(S[j]==T[i]) {
                    table[i][j] = table[i-1][j-1]+table[i][j-1];
                }else {
                    table[i][j]=table[i][j-1];
                }
            }
        }
        return table[row-1][col-1];
    }
