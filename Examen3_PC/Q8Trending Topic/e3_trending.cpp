//https://open.kattis.com/problems/trendingtopic
#include<bits/stdc++.h>
int day = 0;
std::vector<std::string> words[7];
std::map<std::string, int> dict;
std::map<int, std::set<std::string> > reverse_dict;
void Solve(){
while(!std::cin.eof())
  {
    std::string X; 
    std::cin >> X;

    if(X == "<text>") {
      for(auto word: words[day]) {
        dict[word]--;
        if(dict[word] == 0) dict.erase(word);
      }
      words[day].clear();

      std::string word;
      std::cin >> word;
      while(word != "</text>")
      {
        if(word.length() >= 4)
        {
          words[day].push_back(word);
          dict[word]++;
        }
        std::cin >> word;
      }
      day = (day + 1) % 7;
    }
    else if(X == "<top")
    {
      int N; std::cin >> N;
      std::string temp_ignore; 
      std::cin >> temp_ignore;
      reverse_dict.clear();
      for(auto it: dict) 
      {
        if(it.second > 0) 
        {
          reverse_dict[it.second].insert(it.first);
        }
      }

      int print_count = 0;
      std::cout << "<top " << N << ">" << std::endl;
      for(auto it = reverse_dict.rbegin(); 
      print_count < N && it != reverse_dict.rend(); it++)
      {
        for(auto word: it->second)
        {
          std::cout << word << " " << it->first << std::endl;
          print_count++;
        }
      }
      std::cout << "</top>" << std::endl;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solve();
}