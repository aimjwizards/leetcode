    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<int>> table(s.size(), vector<int>(s.size(), INT_MAX));
        for(int i=0; i<s.size(); i++) {
            string word = s.substr(i, 1);
            if(dict.find(word)!=dict.end()) {
                table[i][i] = 1;
            }else{
                table[i][i] = 0;
            }
        }
				// using the length as the progression method
				// traverse the triangle of the status matrix
        for(int len=2; len<=s.size(); len++) {
            for(int i=0; i<=(s.size()-len); i++) {
                int j = i+len-1;
								// see if s<i,j> is a word
                string word = s.substr(i, len);
                if(dict.find(word)!=dict.end()) {
                    table[i][j]=1; continue;
                }
								// see if s<i,k> and s<k+1,j> have combinations
                for(int k=i; k<j; k++) {
                    if(table[i][k]&&table[k+1][j]) {
                        table[i][j]=1;
                        break;
                    }
                }
								// if it wasn't updated it means it doesn't have a combination
                if(table[i][j]==INT_MAX) {
                    table[i][j]=0;
                }
            }
        }
				// return the result from the right corner of the status matrix
        return table[0][s.size()-1];
    }

/*
		status update loop invariant:
( v[i,k] && v[k+1,j] )|| substr[i,j]
		 j
		 _______________
	i |_|_            |
		| |_|_          |
		|   |_|_        |
		|	    |_|_      |
		|       |_|_    |
		|         |_|_  |
		|           |_|_|
    |_____________|_|

*/
