#include <bits/stdc++.h>
void Solution(std::string cadena){
  std::queue<char> teclado;
  std:: string f="";
  int n= cadena.length();
  bool c= false;

  for(int pos =0;pos<n;pos++)
  {
    if(cadena[pos]=='@'){
      if(c){
        c=true;
      }
      else if(cadena[pos]=='$'){
        while(!teclado.empty()){
          if(c){
            f+=toupper(teclado.front());
          }
          else{
            f+=tolower(teclado.front());
          }
        }
      }
      else{
        teclado.push(cadena[pos]);
      }
    }
  }
  std::cout<<f<<std::endl;
}
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  //CASO DE PRUEBA abc$d@ef$@g$
  //output:: abcDEFg
  std::string cadena;
  std::cin>>cadena;
  Solution(cadena);
}