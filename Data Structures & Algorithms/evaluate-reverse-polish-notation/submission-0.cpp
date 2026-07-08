class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        for(auto &ch : tokens){
            if(ch == "+"){
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();

                stack.push(b+a);
            }
            else if(ch == "-"){
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();

                stack.push(b-a);
            }
            else if(ch == "*"){
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();

                stack.push(b*a);
            }
            else if(ch == "/"){
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();

                stack.push(b/a);
            }
            else{
                stack.push(stoi(ch));
            }
        }
        return stack.top();
    }
};