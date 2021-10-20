#include <iostream>
#include <bits/stdc++.h>
#include <stack>
class Solution {
public:
    float scanNum(char ch){
      int value;
      value = ch;
      return float(value-'0');
    }
    int isOperator(char ch){
      if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' )
        return 1;
      return -1;
    }
    int isOperand(char ch){
      if(ch >= '0' && ch <= '9')
        return 1;
      return -1;
    }
    float operation(int a,int b,char op)
    {
      if(op == '+') {return b+a;}
      else if(op == '-') {return b-a;}
      else if(op == '*') {return b*a;}
      else if(op == '/') {return b/a;}
      else return INT_MIN; 
    }
    int evalRPN(std::vector<char>& tokens) 
    {
        int n=tokens.size();
        int v1,v2;
        std::stack<float> stk;
        for(int i=0;i<n;i++)
        {
          if(isOperator(i) != -1)
          {
            v1 = stk.top();
            stk.pop();
            v2 = stk.top();
            stk.pop();
            stk.push(operation(v1, v2, i));
          }
          else if(isOperand(i) > 0)
          {
            stk.push(scanNum(i));
          }
        }
        return stk.top(); 
    }
                            
};
int main(){
   //Leer entrada y salida de forma rapida
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
}