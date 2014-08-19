class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> longest(s.size(), 0);
        int maxLen = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='(') {
                longest[i]=0;
            }else{
                if(i-1>=0) {
                    if(s[i-1]=='(') {
                        longest[i]=2;
                        if(i-longest[i-1]-2>=0 && longest[i-longest[i-1]-2]>0) {
                            longest[i]+=longest[i-longest[i-1]-2];
                        }
                    }else {
                        if(i-longest[i-1]-1>=0 && s[i-longest[i-1]-1]=='(') {
                            longest[i]=2+longest[i-1];
                            if(i-longest[i-1]-2>=0 && longest[i-longest[i-1]-2]>0) {
                                longest[i]+=longest[i-longest[i-1]-2];
                            }
                        }else{
                            longest[i]=0;
                        }
                    }
              
                }
            }
            maxLen =  maxLen>longest[i] ? maxLen : longest[i];
        }
        return maxLen;
    }
};
