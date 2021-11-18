#include <bits/stdc++.h>
class Solution {
  public:
  int h, w;
  void Solve()
  {
    std::cin >> h >> w;
    char T[150][150];
    for(int i = 0; i < 103; i++) 
    {
      for(int j = 0; j < 103; j++)
      {
        T[i][j] = '.';
      }
    }

    for(int i = 1; i <= h; i++)
    {
      for(int j = 1; j <= w; j++){
        std::cin >> T[i][j];
      }
    }

    bool intercambio = true;
    int k = 0;
    while(intercambio)
    {
      k++;
      intercambio = false;
      for(int i = 1; i <= h; i++)
      {
        for(int j = 1; j <= w; j++)
        {
          if(T[i][j] == 'T' && (T[i-1][j] == '.' || T[i+1][j] == '.' || T[i][j-1] == '.' || T[i][j+1] == '.'))
          {
            T[i][j] = k + '0';
            intercambio = true;
          }
          if(T[i][j] == 'T' && (T[i-1][j] == k + '0' - 1 || T[i+1][j] == k + '0' - 1 || T[i][j-1] == k + '0' - 1 || T[i][j+1] == k + '0' - 1)) 
          {
            T[i][j] = k + '0';
            intercambio = true;
          }

        }
      }
    }

    for(int i = 1; i <= h; i++)
    {
      for(int j = 1; j <= w; j++)
      {
        if(k < 10)
        {
          if(T[i][j] == '.')
            std::cout << "..";
          else
            std::cout << '.' << int(T[i][j] - '0');
        }
        else
        {
          if(T[i][j] == '.')
            std::cout << "...";
          else
          {
            if(int(T[i][j] - '0') >= 10)
              std::cout << '.' << int(T[i][j] - '0');
            else
              std::cout << ".." << int(T[i][j] - '0');
          }
        }
     }
     std::cout << '\n';
    }
}

};

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  S1.Solve();
}