class Solution {
public:
    bool parseBoolExpr(string expression) {
        // &(|(f   ))  -? &(f )  -> f
        // operator stack -> {|,!,&}
        // operand stack -> { f,t,( }

        stack<char> oper, operand;

        for(int i=0;i<expression.size();i++){
            char ch = expression[i];
            if(ch == '&' || ch == '!' || ch == '|'){
                oper.push(ch);
            } else if(ch == 't' || ch == 'f' || ch == '('){
                operand.push(ch);
            } else if(ch == ')'){
                //processing the expression
                char operation = oper.top();
                oper.pop();
                if(operation == '&'){
                    bool answer = true;
                    while(operand.top() != '('){
                        bool subExp = (operand.top()=='t')? true: false;
                        operand.pop();
                        answer = answer & subExp;
                    }
                    operand.pop();
                    operand.push((answer)? 't':'f');
                } else if(operation == '|'){
                    bool answer = false;
                    while(operand.top() != '('){
                        bool subExp = (operand.top()=='t')? true: false;
                        operand.pop();
                        answer = answer || subExp;
                    }
                    operand.pop();
                    operand.push((answer)? 't':'f');
                } else{
                    bool answer = (operand.top()=='f')? true: false;
                    operand.pop();
                    operand.pop();
                    operand.push((answer)? 't':'f');
                }
                
            }
        }

        return (operand.top()=='t')? true: false;
    }
};