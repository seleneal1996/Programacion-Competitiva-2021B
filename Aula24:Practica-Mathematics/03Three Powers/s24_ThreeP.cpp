  //https://open.kattis.com/problems/threepowers
  #include <bits/stdc++.h>
  void print_set(int n)
  {
    std::string nums [64]{"1","7","14","783","1125900981634049","0"};
    while(n>0)
    {
      --n;
      std::cout<<'{';
      bool first = true;
      for (int i = 0; i < 64; ++i) {
        if((1ll << i) & n){
          if(!first){
            std::cout << ",";
          }
          first = false;
          std::cout << " " << nums[i];
        }
      }
      std::cout << " }" << std::endl;
      std::cin >> n;
    }
  }
  int main()
  { 
    unsigned long long n;
    std::cin >> n;
    print_set(n);
    return 0;
  }
