    int atoi(const char *str) {
        while(*str==' ') {
            str++;
        }
        int pos;
        if(*str=='-') { pos = -1; str++;}
        else {
            pos=1;
            if(*str=='+') str++;
        }
        
        int result = 0;
        while(*str=='0') {str++;}
        while(isdigit(*str)) {
            int n = str[0]-'0';
            long k=((long)result)*10+n;
            if(k>=INT_MAX) {
                if(pos==1) return INT_MAX;
                else {
                    if(k==INT_MAX) return INT_MIN+1;
                    return INT_MIN;
                }
            }else {
                result= result*10+n;
            }
            str++;
        }
        return pos*result;
    }
