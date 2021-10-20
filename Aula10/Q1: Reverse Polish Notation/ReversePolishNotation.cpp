#include <iostream>
#include <bits/stdc++.h>
class Solution {
public:
    int evalRPN(std::vector<std::string> &tokens) {
        std::stack<int> numbers;
        for (int i = 0; i < tokens.size(); i++) {
            std::string s = tokens[i];
            //es un caracter o no?
            //tam>1
            if (isdigit(s[0]) || s.size() > 1) {
                numbers.push(stoi(s));
                continue;
            }
            int a = numbers.top();
            numbers.pop();
            int b = numbers.top();
            numbers.pop();
            if (s == "+") {
                numbers.push(a+b);
            } else if (s == "-") {
                numbers.push(b-a);
            } else if (s == "*") {
                numbers.push(a*b);
            } else {
                numbers.push(b/a);
            }
        }
        return numbers.top();
    }
};
int main(){
   //Leer entrada y salida de forma rapida
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  }