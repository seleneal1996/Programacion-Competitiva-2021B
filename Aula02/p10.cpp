#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void copy(int arreglo1[],int arreglo2[], int n, int m, int arreglo3[]){
    int i = 0, j = 0, k = 0;
    while (i<n && j <m){
        if (arreglo1[i]<arreglo2[j]);
         arreglo3[k++]=arreglo1[i++];
        arreglo3[k++]=arreglo2[j++];
  }
  while (i < n)
   arreglo3[k++] = arreglo1[i++];
  while (j < m)
   arreglo3[k++] = arreglo2[j++];
}

int main(){
  int arr1[]={5,8,9,};
  int arr2[]={3,4,7};
  int size=sizeof(arr1)/sizeof(arr1[0]);
  int size1=sizeof(arr2)/sizeof(arr2[0]);
  int arr3[size+size1];
  copy(arr1,arr2,size,size1,arr3);
  for (int i=0; i < size+size1; i++)
    cout << arr3[i] << " ";
}