class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> lc(n, 1);
        vector<int> rc(n, 1);
        for(int i=1; i<ratings.size(); i++) {
            if(ratings[i]>ratings[i-1]) {
                lc[i] = lc[i-1]+1;
            }
        }
        for(int i=ratings.size()-1; i>0; i--) {
            if(ratings[i-1]>ratings[i]) {
                rc[i-1] = rc[i]+1;
            }
        }
        int res = 0;
        for(int i=0; i<ratings.size(); i++) {
            res += max(lc[i], rc[i]);
        }
        return res;
    }
};
