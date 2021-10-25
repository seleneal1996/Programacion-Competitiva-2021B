#include <bits/stdc++.h>
#define maximo 3000000
void ordenacao(int vetor[],long long int tam)
{
    long long int i,j,aux;
    for(i=0;i<tam;i++)
        {
        for(j=0;j<tam;j++)
            {
                if(vetor[i]<vetor[j])
                    {
                        aux=vetor[i];
                        vetor[i]=vetor[j];
                        vetor[j]=aux;
                    }
            }
        }
}
int main()
{
  long long int M,i,p,j;
  int k,test,aux;
  int *v;
  v = (int *) malloc(maximo);
  scanf("%d",&test);
  for(k=0;k<test;k++){
    scanf("%lld",&M);
    for(p=0;p<M;p++){
      scanf("%d",&v[p]);
      ordenacao(v,M);
      printf("%d",v[0]);
    }
    
    for(i=1;i<M;i++)
        printf(" %d",v[i]);
     printf("\n");
  }
  return 0;
}