#include <iostream>

int anterior,actual,proximo;

int fibbo_iterativo(int n)
{
  if (n==0)
  	return 0;
  anterior =0;
  actual =1;
  proximo=0;
  for (int i=1;i<n;i++)
  {
  	proximo= anterior+ actual;
  	anterior= actual;
  	actual=proximo;
  }
  return actual;
}

int main()
{
  int n;
  std::cin>>n;
  std::cout << fibbo_iterativo(n);
}