#include <bits/stdc++.h>
#define maxV 10000
#define Vertex int
int V, A, adj[100][100];
int achou,segmentos;


class Solution {
public:

int cnt, lbl[maxV];
void rutaR (Vertex v) {
    Vertex w;
    lbl[v] = cnt++;
    for (w = 0; w < V; w++) {
        if (adj[v][w] == 1) {
            achou =1;
            if (lbl[w] == -1) {
                rutaR(w);
            }
        }
    }
}

void DigrafoPP (void) {
    Vertex v;
    for (v = 0; v < V; v++) {
        lbl[v] = -1;
    }
    for (v = 0; v < V; v++) {
        if (lbl[v] == -1) {
            std::cout << std::endl ;
            segmentos++;
            cnt = 1;
            rutaR(v);

            for (int i = 0; i < V; i++) {
                if (lbl[i] > 0)   {
                    std::cout << char ('a'+i) <<",";
                    lbl[i]=0;
                }
            }
        }
    }
}

};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  char orig,dest;
  int casos;
  std::cin >> casos;
  for(int i = 0; i < casos; i++)
  {
    std::cin >> V; ///Vertices
    for (int j=0; j<V; j++)
    {
      for (int k=0; k<V; k++)
      {
        adj[j][k]=0;
      }
    }
    std::cin >> A; ///Arestas
    for (int j=0; j<A; j++) {
      std::cin >> orig >> dest;
      adj[orig-'a'][dest-'a']++;
      adj[dest-'a'][orig-'a']++;
    }
  
  segmentos=0;
  std::cout << "Case #" << (i+1) << ":";
  S1.DigrafoPP ();
  std::cout <<std::endl<<segmentos<<" connected components\n\n";
  }
  return 0;
}