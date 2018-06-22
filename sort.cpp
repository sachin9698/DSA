#include <iostream>
using namespace std;
#define max 10


//***********************************BUBBLE SORT*******************************
void bsort(int a[]){
  int temp;
  for(int i=0;i<max;i++){
    for(int j=0;j<max-1;j++){
      if(a[j]>a[j+1]){
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
}


//***********************************INSERTION SORT****************************
void isort(int a[]){
  for(int i=1;i<max-1;i++){
    int temp=a[i];
    int j=i-1;
    while((temp<a[j])&&(j>=0)){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=temp;
  }
}


//***********************************SELECTION SORT****************************
void ssort(int a[]){
  int min_ind;
  for(int i=0;i<max-1;i++){
    min_ind=i;
    for(int j=i+1;j<max;j++){
      if(a[j]<a[min_ind]){
        min_ind=j;
      }
    }
    int temp=a[i];
    a[i]=a[min_ind];
    a[min_ind]=temp;
  }
}



//***********************************MERGE SORT*******************************
void merge(int a[],int l,int m,int r){
  int i,j,k;
  int n1=m-l+1;
  int n2=r-m;

  int L[n1], R[n2];

  for(int i=0;i<n1;i++){
    L[i]=a[l+i];
  }
  for(int j=0;j<n2;j++){
    R[j]=a[m+1+j];
  }


  i=0;
  j=0;
  k=l;

  while(i<n1 && j<n2){

    if(L[i]<=R[j]){
      a[k]=L[i];
      i++;
    }
    else{
      a[k]=R[j];
      j++;
    }
    k++;
  }

  while(i<n1){
    a[k]=L[i];
    i++;
    k++;
  }

  while(j<n2){
    a[k]=R[j];
    j++;
    k++;
  }
}

void mergesort(int a[],int l,int r){
  if(l<r){
    int m=l+(r-l)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,m,r);
  }
}


//*********************************QUICK SORT**********************************
void swap(int *a,int *b){
  int t=*a;
  *a=*b;
  *b=t;
}

int partition(int a[],int l,int r){
  int pivot=a[r];
  int i=l-1;

  for(int j=l;j<=r-1;j++){
    if(a[j]<=pivot){
      i++;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[r]);
  return(i+1);
}

void quicksort(int a[],int l,int r){
  if(l<r){
    int p=partition(a,l,r);

    quicksort(a,l,p-1);
    quicksort(a,p+1,r);
  }
}

//*************************************MAIN***********************************
int main(){
  int a[max]={9,8,7,6,5,4,3,2,1,0};
  quicksort(a,0,max-1);
  for(int i=0;i<max;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;

}
