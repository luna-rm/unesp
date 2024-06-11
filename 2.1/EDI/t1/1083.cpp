#include<bits/stdc++.h> 

using namespace std;

int isPos(char a){
    if(a >= '0' && a <= '9'){
        return 1;
    } else if (a >= 'a' && a <= 'z'){
        return 1;
    } else if (a >= 'A' && a <= 'Z'){
        return 1;
    }
    return 0;
}

int main() {

    string expr;
    while(cin >> expr){
        stack<char> order;
        while(expr != ""){
            for(unsigned int i = 0; i < expr.size(); i++){
                cout << expr[i] << endl;
                if(expr[i] == '^'){
                    try
                    {
                        if(expr[i+1] != '('){
                            order.push('^');
                            expr.erase(i);
                            if(isPos(expr[i])){
                                order.push(expr[i]);
                                expr.erase(i);
                            } else {
                                cout << "Lexical Error!" << endl;
                            }
                            continue;
                        }
                    }
                    catch(const std::exception& e)
                    {
                        cout << "Syntax Error!" << endl;
                        break;
                    } 
                }

                if(expr[i] == '*' || expr[i] == '/'){
                    try
                    {
                        if(expr[i+1] != '('){
                            order.push(expr[i]);
                            expr.erase(i);
                            if(isPos(expr[i])){
                                order.push(expr[i]);
                                expr.erase(i);
                            } else {
                                cout << "Lexical Error!" << endl;
                            }
                            continue;
                        }
                    }
                    catch(const std::exception& e)
                    {
                        cout << "Syntax Error!" << endl;
                        break;
                    } 
                }

                if(expr[i] == '+' || expr[i] == '-'){
                    try
                    {
                        if(expr[i+1] != '('){
                            order.push(expr[i]);
                            expr.erase(i);
                            if(isPos(expr[i])){
                                order.push(expr[i]);
                                expr.erase(i);
                            } else {
                                cout << "Lexical Error!" << endl;
                            }
                            continue;
                        }
                    }
                    catch(const std::exception& e)
                    {
                        cout << "Syntax Error!" << endl;
                        break;
                    } 
                }

                if(expr[i] == '>' || expr[i] == '<' || expr[i] == '=' || expr[i] == '#'){
                    try
                    {
                        if(expr[i+1] != '('){
                            order.push(expr[i]);
                            expr.erase(i);
                            if(isPos(expr[i])){
                                order.push(expr[i]);
                                expr.erase(i);
                            } else {
                                cout << "Lexical Error!" << endl;
                            }
                            continue;
                        }
                    }
                    catch(const std::exception& e)
                    {
                        cout << "Syntax Error!" << endl;
                        break;
                    } 
                }

                if(expr[i] == '.'){
                    try
                    {
                        if(expr[i+1] != '('){
                            order.push(expr[i]);
                            expr.erase(i);
                            if(isPos(expr[i])){
                                order.push(expr[i]);
                                expr.erase(i);
                            } else {
                                cout << "Lexical Error!" << endl;
                            }
                            continue;
                        }
                    }
                    catch(const std::exception& e)
                    {
                        cout << "Syntax Error!" << endl;
                        break;
                    } 
                }

                if(expr[i] == '|'){
                    try
                    {
                        if(expr[i+1] != '('){
                            order.push(expr[i]);
                            expr.erase(i);
                            if(isPos(expr[i])){
                                order.push(expr[i]);
                                expr.erase(i);
                            } else {
                                cout << "Lexical Error!" << endl;
                            }
                            continue;
                        }
                    }
                    catch(const std::exception& e)
                    {
                        cout << "Syntax Error!" << endl;
                        break;
                    } 
                }

                if(isPos(expr[i])){
                    order.push(expr[i]);
                    expr.erase(i);
                    break;
                } else {
                    cout << "Lexical Error!" << endl;
                }

            }

            while(!order.empty()){
                cout << order.top();
                order.pop();
            }
        }

    }

    return 0;
}