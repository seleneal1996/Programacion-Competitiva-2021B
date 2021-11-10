#include <bits/stdc++.h>
class Solution {
public:

    void dfs(int x,int y,std::vector<std::vector<int>>& image,int color,int last)
    {
        int n=image.size();
        int m=image[0].size();
        /*si llegamos a una situación terminal, de lo contrario, la ejecutamos alrededor del ultimo punto que verificamos hasta que encontramos algo que valga la pena verificar.*/
        if(x>=n || x<0 || y>=m || y<0 || image[x][y]!=last){
            return;
        }  
        image[x][y]=color;
        dfs(x+1,y,image,color,last);
        dfs(x-1,y,image,color,last);
        dfs(x,y+1,image,color,last);
        dfs(x,y-1,image,color,last);        
    }
    
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        /*Llamo a la función dfs solo si el nuevo color es diferente al inicial*/
        if(newColor!=image[sr][sc]){
            dfs(sr,sc,image,newColor,image[sr][sc]);
        }
        return image;
    }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //caso de prueba
  std::vector<std::vector<int>>grid= {{1,1,1},{1,1,0},{1,0,1}};
  S1.floodFill(grid,1,1,2);
  return 0;
}