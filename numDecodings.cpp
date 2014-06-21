    int numDecodings(string s) {
        if(s.size()==0) return 0;
        if(s[0]=='0') return 0;
        if(s.size()==1) return 1;
        vector<int> table(s.size(), 0);
				// dynamic programming building the table
        table[0]=1; 
				// 30 won't make it
        if(s[0]>='3') {
            if(s[1]=='0') return 0;
            table[1]=1;
        } // 20 or 27, 28, 29 -->1
				else if(s[0]=='2') {
            if(s[1]>'6' || s[1]=='0') table[1]=1;
            else table[1]=2; // o.w. 2
        } else { // 10 ->1
            if(s[1]=='0') table[1]=1;
						// 1* ->2
            else table[1]=2;
        }
        for(int i=2; i<s.size(); i++) {
            if(s[i]=='0') {
								// 0 is a dragger, check the prev digit, 1, 2 would continue;
                if(s[i-1]=='1'||s[i-1]=='2') {table[i]=table[i-2]; }
								// bigger than 30 invalidates
                else return 0;
            }else if(s[i]>'6') {
								// the last digit is 6
                if(s[i-1]=='1') {
										// the prev is 1 it uses 16 or 6+prev
                    table[i] = table[i-1]+table[i-2];
                }else {
										// else standalone number
                    table[i] = table[i-1];
                }
            }else{
                if(s[i-1]=='1'||s[i-1]=='2') {
                    table[i] = table[i-1]+table[i-2];
                }else{
                    table[i] = table[i-1];
                }
            }
        }
        return table[s.size()-1];
    }
