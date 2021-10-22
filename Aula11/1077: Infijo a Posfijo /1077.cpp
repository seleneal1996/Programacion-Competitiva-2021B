#include <bits/stdc++.h>
int priority(char simbolo){
    switch(simbolo){
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
            case '^':
        return 3;
            default :
        return 0;
    }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::string cadena;
  std::stack <char> Stack;
  std::vector <char> salida;
  int tc;
  std::cin>>tc;
  while(tc--){
    std::cin>>cadena;
    for(int i=0;i<cadena.length();i++){
      if( cadena[i] == '+' || cadena[i] == '-' || cadena[i] == '*' || cadena[i] == '/' || cadena[i] == '^'){
        while( !Stack.empty() && priority(Stack.top()) >= priority(cadena[i]) ){
          salida.push_back(Stack.top());
          Stack.pop();
        }
        Stack.push(cadena[i]);
      }
      else if(cadena[i] == '('){
        Stack.push(cadena[i]);
      }
      else if( cadena[i]==')' ){
        while( Stack.top() !='(' ){
          salida.push_back(Stack.top());
          Stack.pop();
        }
        Stack.pop();
      }
      else {
        salida.push_back(cadena[i]);
      }
 
    }
    
    while( !Stack.empty() ){
      salida.push_back(Stack.top());
      Stack.pop();
    }
 
    for(int i=0;i<salida.size();i++){
      std::cout<<salida[i];
    }
    std::cout<<std::endl;
    while(!salida.empty()){
      salida.pop_back();
    }
 
  }
  return 0;
}
