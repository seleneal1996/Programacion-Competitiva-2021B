//INTEST - Enormous Input Test
#include <iostream>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m,l,y;
  int cont=0;
  cin>>m>>l;

  while(m--){
    cin>>y;
    cont=(y%l==0)?cont+1:cont;
  }
  cout<<cont<<"\n";
}