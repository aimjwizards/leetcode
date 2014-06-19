
    void reverseWords(string &s) {
        if (s.size()==0) return;
        while(s[0]==' ') s.erase(s.begin());
        for(int i=0, j=s.size()-1; i<j; i++, j--) {
            swap(s[i], s[j]);
        }
        while(s[0]==' ') s.erase(s.begin());
        int start=0, end=0;
        while(end<s.size()) {
            while((end+1<s.size())&&s[end+1]!=' ') end++;
            for(int i=start, j=end; i<j; i++, j--) {
                swap(s[i], s[j]);
            }
            end+=2;
            start=end;
        }
        start=0; end=0;
        while(end<s.size()) {
            if(s[end]!=' ') s[start++]=s[end++];
            else {
                if(s[end-1]==' ') {end++;}
                else { s[start++]=s[end++];}
            }
            
        }
        s.erase(s.begin()+start, s.end());
    }
