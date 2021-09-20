#include <iostream>
#include <stdio.h>
#include <stdlib.h>
struct Nodo
{
int dat;
struct Nodo *next;
};
struct Nodo *createNodo(int dat)
 {
struct Nodo *n;
n = (struct Nodo *)malloc(sizeof(struct Nodo));
n->dat = dat;
n->next = NULL;
return n;
}
void traverseList(struct Nodo *head)
{
while (head != NULL)
{
    printf("%d ", head->dat);
    head = head->next;
}
}
void remove(struct Nodo *head){
struct Nodo *ptr = head;
while (ptr != NULL)
{
    struct Nodo *runner = ptr;
    while (runner->next != NULL)
    {
        if (ptr->dat == runner->next->dat)
        {
            runner->next = runner->next->next;
        }
        else
        {
            runner = runner->next;
        }
    }
    free(runner->next);
     ptr = ptr->next;
 }
 }
 int main()
 {
struct Nodo *Nodo1, *Nodo2, *Nodo3, *Nodo4;
Nodo1 = createNodo(2);
Nodo2 = createNodo(5);
Nodo3 = createNodo(5);
Nodo4 = createNodo(1);
Nodo1->next = Nodo2;
Nodo2->next = Nodo3;
Nodo3->next = Nodo4;
Nodo4->next = NULL;
traverseList(Nodo1);
remove(Nodo1);
printf("\n");
traverseList(Nodo1);

return 0;
}

