//https://leetcode.com/problems/keys-and-rooms/
#include <bits/stdc++.h>
class Solution {
public:
    std::unordered_set<int>visited; 
    int n=visited.size();
    void dfs(int room,std::vector<std::vector<int>>& rooms){
        
        if(visited.count(room))
            return;
        visited.insert(room);      
        for(auto key:rooms[room])
        { 
            dfs(key,rooms);       
        }
    }
    
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) {
        dfs(0,rooms);
        return rooms.size()==visited.size(); 
    }
};

int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Solution S1= Solution();
  //CASO DE PRUEBA = [[1],[2],[3],[]]
  // SALIDA= 1
  std::vector<std::vector<int> >rooms={{1},{2},{3},{}};
  std::cout<<S1.canVisitAllRooms(rooms);
}
