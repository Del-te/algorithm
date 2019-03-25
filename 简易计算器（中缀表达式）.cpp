#include <iostream>
#include <cctype>
#include <cstring>
#include <stack>
using namespace std;
char calcu[10000];
stack<char> ope;
stack<int> num;
 
int calculate(int a, int b, char c){
    switch (c) {
        case '+': return a + b; break;
        case '-': return a - b; break;
        case '*': return a * b; break;
        case '/': return a / b; break;
        default: return -1;
    }
}
int main(){
    scanf("%s", calcu);
    int len = (int)strlen(calcu);
   
    for(int i = 0; i<len; i++){
        if(isdigit(calcu[i])){
            int temp = 0;
            while(i < len && isdigit(calcu[i])){
                temp = temp * 10 + calcu[i] - '0';
                i++;
            }
            num.push(temp);
            i--;
        }
        else{
            if(calcu[i] == ')'){
                while(ope.top() != '(' && !ope.empty()){
                    int temp1 = num.top(); num.pop();
                    int temp2 = num.top(); num.pop();
                    num.push(calculate(temp2, temp1, ope.top()));
                    ope.pop();
                }
                if(!ope.empty()) ope.pop();
            }
            else if(calcu[i] == '(') ope.push(calcu[i]);
            else if(calcu[i] == '+' || calcu[i] == '-'){
                while(!ope.empty() && ope.top() != '('){
                    int temp1 = num.top(); num.pop();
                    int temp2 = num.top(); num.pop();
                    num.push(calculate(temp2, temp1, ope.top()));
                    ope.pop();
                }
                ope.push(calcu[i]);
            }
            else{
                while(!ope.empty() && ope.top() != '+' && ope.top() != '-' && ope.top() != '('){
                    int temp1 = num.top(); num.pop();
                    int temp2 = num.top(); num.pop();
                    num.push(calculate(temp2, temp1, ope.top()));
                    ope.pop();
                }
                ope.push(calcu[i]);
            }
        }
    }
    while(!ope.empty()){
        int temp1 = num.top(); num.pop();
        int temp2 = num.top(); num.pop();
        num.push(calculate(temp2, temp1, ope.top()));
        ope.pop();
    }
    
    cout<<num.top();
    system("pause");
    return 0;
}
