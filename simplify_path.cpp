string simplifyPath(string path) {
    if(path.size()==0) return "";
    int start = -1;
    vector<string> p;
    for(int i=0;i<path.size(); i++) {
        if(path[i]=='/') {
            if(start==-1)  { p.push_back("/"); start =i+1;}
            else{
                string s = path.substr(start, i-start);
                if(s!="") { p.push_back(s);}
                p.push_back("/");
                start = i+1;
            }
        }
    }
    if(start<path.size()) {
        p.push_back(path.substr(start));
    }
    vector<string> r;
    for(int i=0; i<p.size(); i++) {
        if(p[i]=="/") {
            if(!r.empty()&&r.back()=="/") continue;
            else r.push_back(p[i]);
        }else if(p[i]==".") {
            continue;
        }else if(p[i]=="..") {
            if(r.size()>2) {r.pop_back();r.pop_back();}
        }else{
            r.push_back(p[i]);
        }
    }
    while(r.size()>1 &&(r.back()=="/"||r.back()==".")) r.pop_back();

    string result;
    for(int i=0; i<r.size(); i++) {
        result+=r[i];
    }
    return result;
}
