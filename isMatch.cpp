class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // match end
        if(*p=='\0') return *s=='\0';
        if(*(p+1)!='*') {
            // match single word
            if(*p=='.'&&*s!='\0') return isMatch(s+1, p+1);
            else{
                if(*s==*p) return isMatch(s+1, p+1);
                else return false;
            }
        }else {
            //starting from the count equal to 0,
            //increment by one each time.
            while((*p=='.'&&*s!='\0')||*p==*s) {
                if(isMatch(s, p+2)) return true;
                s++;
            }
            // aab vs c*a*b   the count of c==0
            return isMatch(s, p+2);
            
        }
        

    }
};
