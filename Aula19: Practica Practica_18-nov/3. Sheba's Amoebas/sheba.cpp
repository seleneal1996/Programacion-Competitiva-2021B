//https://open.kattis.com/problems/amoebas
#include <bits/stdc++.h>
class Solution {
  public:
  void amoebaCount(int i, int x, int j, int y, std::vector<bool> &v)
  {
    v[i*y+j] = false;
    for(int k = -1; k < 2; k++)
    {
      for(int l = -1; l < 2; l++)
      {
        if(k == 0 && l == 0){
          continue;
        }
        i += k;
        j += l;
        if((i<x && i>= 0) && (j<y &&j >= 0 && v[i * y + j]))
          amoebaCount(i, x, j, y, v);
        i-= k;
        j-= l;
      }
    }
  }

};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  Solution S1= Solution();
  //casos de prueba
  /*12 12
.##########.
#..........#
#..#...##..#
#.##..#..#.#
#......#.#.#
#....#..#..#
#...#.#....#
#..#...#...#
.#..#.#....#
#....#.....#
#.........#.
.#########..

SALIDA:4

12 10
.#####....
#.....#...
#..#..#...
#.#.#.#...
#..#..#...
.#...#....
..###.....
......#...
.##..#.#..
#..#..#...
.##.......
..........

SALIDA: 4
*/
  int x, y;
  std::cin >> x >> y;
  char pixel;
  std::vector<bool> A(x * y);
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++)
    {
      std::cin >> pixel;
      A[i*y+j] = (pixel == '#');
    }
  }
  
  int Count = 0;
    for(int i = 0; i < x; i++)
    {
      for(int j = 0; j < y; j++)
      {
        if(A[i * y + j]){
          Count++;
          S1.amoebaCount(i, x, j, y, A);
        }
      }
    }
    std::cout << Count << std::endl; 
  return 0;
}