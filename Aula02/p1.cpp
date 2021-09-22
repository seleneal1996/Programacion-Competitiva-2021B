#include <iostream>
#include <bits/stdc++.h>
using std::cout; using std::cin;
using std::endl; using std::string;
#include <string>
#include <strings.h>

bool esAnagrama(std::string str1, std::string str2)
{
  int pal1= str1.length();
  int pal2= str2.length();
  if (pal1!=pal2) return false;
  sort(str1.begin(),str1.end());
  sort(str2.begin(),str2.end());
  for (int i =0;i<pal1;i++)
  {
    if (str1[i]!=str2[i]) return false;
    return true;
  }
}
int main() {
  std::string pal1,pal2;
  //std::cin>> pal1.erase(std::remove(pal1.begin(), pal1.end(), ' '), pal1.end());
  //std::cin>> pal2.erase(std::remove(pal2.begin(), pal2.end(), ' '), pal2.end());
  std::cin>> pal1;
  std::cin>> pal2;
  pal1.erase(std::remove(pal1.begin(), pal1.end(), ' '), pal1.end());
  pal2.erase(std::remove(pal2.begin(), pal2.end(), ' '), pal2.end());
  if(esAnagrama(pal1,pal2))
    std::cout<<"Si";
}