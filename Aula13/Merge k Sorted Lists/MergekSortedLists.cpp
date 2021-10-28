#include <bits/stdc++.h>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    struct comparexx{
        bool operator()(ListNode*A,ListNode*B){
            return A->val > B->val;
        }
    };
    
    ListNode*mergeKLists(std::vector<ListNode*>& lists){
        std::priority_queue<ListNode*,std::vector<ListNode*>,comparexx> AB;
        for(auto A: lists){
            if(A) AB.push(A);
        }    
        if(AB.empty()){
            return nullptr;
        }
        
        ListNode* rpta = AB.top(); AB.pop();
        ListNode* tail = rpta;
        if(tail->next) AB.push(tail->next);
        while(!AB.empty()){
            tail->next = AB.top(); AB.pop();
            tail = tail->next;
            if(tail->next) {
                AB.push(tail->next);
            }
        }
        return rpta;
        
    }
};
int main(){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  return 0;
}