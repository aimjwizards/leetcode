    bool helper(vector<vector<char>> &board, string word, int x, int y) {
        if(board[x][y]==word[0]) {
						// when it's the last char in the word, 
						// terminate the recursion and return true;
            if (word.size()==1) return true;
            char c = board[x][y];
            board[x][y] = '*';
            if(x+1<board.size() &&board[x+1][y]!='*') {
                if(helper(board, word.substr(1), x+1, y)) {
                    return true;
                }
            }
            if(x-1>=0 && board[x-1][y]!='*') {
                if(helper(board, word.substr(1), x-1, y)) {
                    return true;
                }
            }
            if(y+1<board[0].size() &&board[x][y+1]!='*') {
                if(helper(board, word.substr(1), x, y+1)) {
                    return true;
                }
            }
            if(y-1>=0 && board[x][y-1]!='*') {
                if(helper(board, word.substr(1), x, y-1))  {
                    return true;
                }
            }
						// unmark the symbol
						// backtracking
            board[x][y]=c;
        }
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        if(word=="") return true;
        if(board.size()==0) return false;
        if(word.size()>(board[0].size()*board.size())) return false;
        vector<int> words(256, 0);
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                words[board[i][j]]+=1;
            }
        }
        for(auto c:word) {
            words[c]--;
            if(words[c]<0) return false;
        }
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j]==word[0]) {
                    if(helper(board, word, i, j)) return true;
                }
            }
        }
        return false;
    }
