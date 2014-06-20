
    void buildTable(string &s, vector<vector<int>> &table) {
        for(int i=0; i<s.size(); i++) {
            table[i][i] = 1;
        }
        for(int i=0; i<s.size()-1; i++) {
            if(s[i]==s[i+1]) {
                table[i][i+1]=1;
            }
        }
        for(int len=3; len<=s.size(); len++) {
            for(int i=0, j=i+len-1; j<s.size(); i++, j++) {
                if(table[i+1][j-1]==INT_MAX) continue;
                if(s[i]==s[j]) table[i][j]=1;
            }
        }
        
    }


    void Helper(string s, int start, vector<string> &tmp, vector<vector<string>> &result, vector<vector<int>> &table) {
        if(start==s.size()) {
            result.push_back(tmp);
        }
        
        for(int i=start; i<s.size(); i++) {
            if(table[start][i]==INT_MAX) continue;
            string sub = s.substr(start, i-start+1);
            tmp.push_back(sub);
            Helper(s, i+1, tmp, result, table);
            tmp.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if(s.size()==0) return result;
        vector<vector<int>> table(s.size(), vector<int>(s.size(), INT_MAX));
        buildTable(s, table);
        vector<string> tmp;
        Helper(s, 0, tmp, result, table);
        return result;
    }
