    string countAndSay(int n) {
        if(n<1) return "";
        string output="1"; string input="";
        for(int i=1; i<n; i++) {
            swap(input, output);
            output.clear();
            char digit = input[0];
            int count =1;
            for(int j=1; j<input.size(); j++) {
                if(input[j]!=digit){
                    output+=(char)'0'+ count;
                    output+=(char)digit;
                    digit=input[j];
                    count=1;
                }else{
                    count ++;
                }
            }
            output+= (char) '0'+count;
            output+=(char) digit;
        }
        return output;
    }
