#include <bits/stdc++.h>
//Deque: double-ended queue

void Solution(std::string cadena)
{
  std :: deque <char > d;
  std:: string f="";
  int n= cadena.length();
  for(int pos =0;pos<n;pos++)
  {
    if(cadena[pos]=='#')
    {
      d.pop_back();
    }
    else
    {
      d.push_back(cadena[pos]);
    }
  }
  for(auto it=d.begin();it!=d.end();it++){
    f+=*it;
  }
  std::cout<<f<<std::endl;
}
int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::string cadena="abc#de##f#ghi#jklmn#op#";
  Solution(cadena);
}