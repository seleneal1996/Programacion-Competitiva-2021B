#include <bits/stdc++.h>
int n,k,m,j,der = 0,cont = 0,sOff = 0;
int izq = n-1;
int main () 
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    bool A[20];
    while (std::cin >> n >> k >> m)
    {
      if (n == 0 && k == 0 && m == 0)
      {
        return 0;
      }
      for (int i = 0; i < 20; i++)
      {
        A[i] = false;
      }
      for (int i = 0; i < n; i++)
      {
        A[i] = true;
      }
      while (sOff < n)
      {
        j = der;
        cont = 0;
        while (cont < m) 
        {
          if (j == 0)
          {
            j = n - 1;
          }
          else
          {
            --j;
          }
          if (A[j] == true)
          {
            cont++;
          }
          der = j;
          j = izq;
          cont = 0;
          while (cont < k)
          {
            if (j == n-1)
            {
              j = 0;
            }
            else
            {
              ++j;
            }
            if (A[j] == true)
            {
              cont++;
            }
          }
          
          izq = j;
          if (sOff > 0){
            std::cout << ",";
          }
          if (izq == der){
            /*Establece el ancho del campo que se utilizará en las operaciones de salida.*/
            std::cout << std::setw(3) << izq + 1;
            sOff += 1;
          } 
          else
          {
            std::cout << std::setw(3) << izq + 1 << std::setw(3) << der + 1;
            sOff += 2;
        }
        A[izq] = false;
        A[der] = false;
        }
        std::cout << '\n';
        }
    return 0;
    }
}
