//https://www.beecrowd.com.br/judge/en/problems/view/1642
#include <bits/stdc++.h>
char text[1000010];
int keys;
int tam = 0;
class BrokenKeyboard{
public:

  int BiggerSubstring(){
    int rec_subcadenas[128];
    int cStart = 0, cEnd = keys-1;
    int tam_Act_txt = strlen(text);
    int keys_used = 0, counter_aux = 0;

    for (int i = 0; i < 128; ++i)
      rec_subcadenas[i] = 0;

    for (int i = 0; i < keys; ++i){
      if(rec_subcadenas[text[i]] == 0){
        keys_used++;
      }
      rec_subcadenas[text[i]]++;
    }

    while(cEnd < tam_Act_txt-2){
      while(keys_used <= keys && (cEnd < tam_Act_txt-2)){
        cEnd++;
        if(rec_subcadenas[text[cEnd]] == 0){
          keys_used++;
        }
        rec_subcadenas[text[cEnd]]++;
      }
      
      if(keys_used > keys){
        cStart++;
      }
      if((cEnd - cStart + 1) > tam){
        tam = cEnd - cStart + 1;
      }
      
      if(rec_subcadenas[text[cStart-1]] > 0){
        rec_subcadenas[text[cStart-1]]--;
        counter_aux = rec_subcadenas[text[cStart-1]];
        if(counter_aux == 0){
          keys_used--;
        }
      }
    }
    return 0;
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  BrokenKeyboard S1= BrokenKeyboard();
  while(true)
  {
    tam = 0;
    scanf("%d", &keys);
    getchar();
    if(keys != 0){
      if(fgets(text, 1000010, stdin) != NULL){
        S1.BiggerSubstring();
      }
      printf("%d\n", tam);
    }
    else{
      break;
    }
  }
  return 0;
}