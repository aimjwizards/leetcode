vector<vector<int> > permute(vector<int> &num)
{
    vector<vector<int>> result;
    if (num.size()==1) {
        result.push_back(num);
        return result;
    }

    
    for (int i=0; i<num.size(); i++) {
        swap(num[0], num[i]);
        vector<int> subnum(num.begin()+1, num.end());
        vector<vector<int>> subresult = permute(subnum);
        for (auto &av: subresult) {
            av.insert(av.begin(), num[0]);
            result.push_back(av);
        }
        swap(num[0], num[i]);
    }
    return result;
}
