//https://open.kattis.com/problems/dungeon

#include <bits/stdc++.h>
int L,R,C;
char s[31][31][31];
int look_in_on[31][31][31];
int sx,sy,sz;
bool banner;
int footstep[6][3]={{0,0,-1},{0,0,1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};
class Points{
  public:
  struct my_point{
    int x,y,z;
    int conti;
  }f,g;
};
class Dungeon:public Points{
  public:
  void bfs()
  {
    std::queue<my_point>q;
    while(!q.empty())
      q.pop();
      memset(look_in_on,0,sizeof(look_in_on));
      f.x=sx;
      f.y=sy;
      f.z=sz;
      f.conti=0;
      look_in_on[f.x][f.y][f.z]=1;
      q.push(f);
      while(!q.empty())
      {
        f=q.front();
        q.pop();
        if(s[f.x][f.y][f.z]=='E')
        {
          std::cout<<"Escaped in "<<f.conti<<" minute(s)."<<"\n";
          banner=true;
        }
        
        for(int i=0;i<6;i++)
        {
          g.x=f.x+footstep[i][0];
          g.y=f.y+footstep[i][1];
          g.z=f.z+footstep[i][2];
          if(g.x>=0&&g.x<L&&g.y>=0&&g.y<R&&g.z>=0&&g.y<C)
          {
            if(!look_in_on[g.x][g.y][g.z]&&s[g.x][g.y][g.z]!='#')
            {
              g.conti=f.conti+1;
              look_in_on[g.x][g.y][g.z]=1;
              q.push(g);
            }
          }
        }
      }
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  Dungeon S1= Dungeon();
  while(std::cin>>L>>R>>C&&L&&R&&C)
  {
    for(int i=0;i<L;i++)
    for(int j=0;j<R;j++)
    for(int k=0;k<C;k++)
    {
      std::cin>>s[i][j][k];
      if(s[i][j][k]=='S'){
        sx=i,sy=j,sz=k;
      }
    }

    banner=false;
    S1.bfs();
    if(!banner){
      std::cout<<"Trapped!"<<"\n";
    }
  }
  return 0;
}   