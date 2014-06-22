    void process(vector<string> &words, vector<string>&result, int start, int end, int L) {
        int size = 0;
        if(end==words.size()-1 ) {
            string s;
            int last_space = L;
            for(int i=start; i<=end; i++) {
                last_space-=words[i].size();
                s+=words[i];
                if(i!=end) {
                    s+= " ";
                    last_space--;
                }else {
                    s+= string(last_space, ' ');
                }
            }
            result.push_back(s); return;
        }

        for(int i=start; i<=end; i++) {
            size+=words[i].size();
        }
        int space = L-size;
        if(start==end) {
            string s = words[start];
            s+= string((L-size), ' ');
            result.push_back(s); return;
        }
        int e_space = space/(end-start);
        int n=space-e_space*(end-start);
        string s;
        for(int i=start; i<=end; i++) {
            s+= words[i];
            if(i!=end) {
                s+=string(e_space, ' ');
            }
            if(n>0) {
                s+=string(1, ' '); n--;
            }
        }
        result.push_back(s);
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        if (L<0) return result;
        if(words.size()==0) return result;
        int start = 0; int sofar = 0;
        for(int i=0; i<words.size(); i++) {
            if(i+1<words.size() && (sofar+words[i].size()+words[i+1].size()<L)) {
                sofar = sofar+ words[i].size()+1;
            }else if(i+1<words.size() && (sofar+words[i].size()+words[i+1].size()==L)) {
                process(words, result, start, i, L);
                start = i+1; sofar = 0; 
            }else{
                process(words, result, start, i, L);
                start = i+1; sofar = 0;
            }
        }

        return result;
    }     


