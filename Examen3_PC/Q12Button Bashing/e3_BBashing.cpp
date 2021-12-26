//https://open.kattis.com/problems/buttonbashing
#include<bits/stdc++.h>
std::vector<int> adj_list;
std::vector<int> buttons;
class ButtonBash{
public:
  void BFS()
  {
    std::queue<int> q;
    q.push(0);
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      for (auto &v : buttons)
      {
        int selected = u + v;
        selected = fmin(3600, fmax(0, selected));
        if (adj_list[selected] > adj_list[u] + 1) 
        {
          adj_list[selected] = adj_list[u] + 1;
          q.push(selected);
        }
      }
    }
  }

};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  ButtonBash b1=ButtonBash();
  int cases; 
  std::cin >> cases;
  for (int i = 0; i < cases; i++)
  {
    buttons.clear();
    adj_list.assign(3601, 1e9);
    adj_list[0] = 0;
    int number;
    int duration;
    std::cin >> number >> duration;
    for (int j = 0; j < number; j++)
    {
      int input; 
      std::cin >> input;
      buttons.push_back(input);
    }
    b1.BFS();
    for (int j = duration; j < 3601; j++)
    {
      if (adj_list[j] != 1e9)
      {
        std::cout << adj_list[j] << " " << j - duration << "\n";
        break;
      }
    }
  }
}