// Things to notice:
// 1) remember the order of the operands in the stack
// 2) remember the positive and negative sign of operands to confuse operator

    bool isOperator(string token) {
        if(token.size()!=1) return false;
        switch(token[0]) {
            case '+':
            case '-':
            case '*':
            case '/': return true;
            default: return false;
        }
    }
    int evalRPN(vector<string> &tokens) {
        if (tokens.size()==0) return 0;
        stack<string> s;
        for(auto token: tokens) {
            if(isOperator(token)) {
                int o2 = stoi(s.top()); s.pop();
                int o1 = stoi(s.top()); s.pop();
                int result;
                switch(token[0]) {
                    case '+': result = o1+o2; break;
                    case '-': result = o1-o2; break;
                    case '*': result = o1*o2; break;
                    case '/': result = o1/o2; break;
                }
                s.push(to_string(result));
            }else {
                s.push(token);
            }
        }
        return stoi(s.top());
    }
