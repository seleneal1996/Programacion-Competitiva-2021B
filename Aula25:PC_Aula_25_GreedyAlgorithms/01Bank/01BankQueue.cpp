//https://open.kattis.com/problems/bank
#include <bits/stdc++.h>
 
class Person{
  int money,time;
  public:
  Person(int, int);
  bool compareMoney(const Person &a, const Person &b);
  void queuePerson(std::vector<int> &v, Person c);
};
Person::Person(int m, int w){
  money = m;
  time = w;
}
bool Person::compareMoney(const Person &a, const Person &b){
  return a.money >= b.money;
}
  
void Person::queuePerson(std::vector<int> &v, Person c){
  int i = c.time;
  while(i >= 0){
    if(v[i] == 0){
      v[i] = c.money;
      return;
    }  
    i--; 
  }
}

int main()
{ 
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  Person P(4,4);
  int N, T, ci, ti;
  int sum = 0,i = 0;
  scanf("%d %d", &N, &T);
  std::vector<int> bQueue(T);
  std::vector<Person> money;
  for(int i = 0; i < N; i++)
  {
    scanf("%d %d", &ci, &ti);
    Person c(ci, ti);
    money.push_back(c); 
  }
  sort(money.begin(), money.end(), P.compareMoney(Person(ci, ti), Person(ci, ti)));
  while(i < money.size()){
    P.queuePerson(bQueue, money[i]);
    i++;
  }
  
  for(int i = 0; i < bQueue.size(); i++)
  {
    sum += bQueue[i];
  }
    
  printf("%d", sum); 
  return 0; 
}