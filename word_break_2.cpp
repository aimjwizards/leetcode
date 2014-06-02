class Solution {
public:


vector<vector<int> > genTable(string &s, unordered_set<string> &dict)
{
    int n = s.length();
    vector<vector<int> > tbl(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if(dict.count(s.substr(i))) tbl[i].push_back(n-1);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        // if we can break into i+1
        // continue with i
        if (!tbl[i+1].empty())//if we can break i->n
        {
            for (int j = i, d = 1; j >= 0 ; j--, d++)
            {
                if (dict.count(s.substr(j, d))) tbl[j].push_back(i); // see if we can break j->i
            }
        }
    }
    return tbl;
}

void Helper(vector<string> &result, string &s, string &tmp, int start, vector<vector<int>> &t2, unordered_set<string> &dict)
{
    if(start==s.size() ) {
        result.push_back(tmp);
        return;
    }
    
    for(int i=0; i< t2[start].size(); i++) {
        string sub = s.substr(start, t2[start][i]-start+1);
        string newtmp = tmp;
        if(newtmp!=""){
            newtmp =newtmp +" "+ sub;
        }else {
            newtmp = sub;
        }
        int nextstart = t2[start][i]+1;
        Helper(result, s, newtmp, nextstart, t2, dict);
        
    }
    return;
    
}
vector<string> wordBreak(string s, unordered_set<string> &dict) {
    vector<vector<int>> t2 = genTable(s, dict);
    string tmp="";
    vector<string> result;
    Helper(result, s, tmp, 0, t2, dict);
    
    return result;
}

}; 
