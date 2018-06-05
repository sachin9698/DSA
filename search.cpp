#include <iostream>
#include <algorithm>
using namespace std;
#define max 10

void lsearch(int a[],int m){
  int p=0;
  for(int i=0;i<max; i++){
    if(m==a[i]){
      cout<<"value found !"<<endl;
      p=1;
      return;
    }
  }
  if(p==0){
    cout<<"value not found !"<<endl;
  }
}

void bserach(int a[],int m,int s){
  int f,l,mid;
  f=0;
  l=s-1;

  while(f<=l){
    mid=(f+l)/2;
    if(m==a[mid]){
      cout<<"value found !"<<endl;
      return;
    }
    else {
      if(m<a[mid]){
         l=mid-1;
       }
      else {
        f=mid+1;
      }
    }
  }

  cout<<"value not found !"<<endl;
  return;
}

void iserach(int a[],int m,int s){
  int f,l,mid;
  f=0;
  l=s-1;

  while(a[f] <= m && a[l] >= m){
    mid=f + ((m - a[f]) * (l - f)) / (a[l] - a[f]);
    if(m==a[mid]){
      cout<<"value found !"<<endl;
      return;
    }
    else {
      if(m<a[mid]){
         l=mid-1;
       }
      else {
        f=mid+1;
      }
    }
  }

  cout<<"value not found !"<<endl;
  return;
}

int main() {
  int a[max]={1,2,3,4,7,6,5,8,9,10};

  // for(int i=0; i<max; i++){
  //   cout<<a[i]<<" ";
  // }
  // lsearch(a,12);
  sort(a,a+max);                    //data must be sorted for binary and interpolation serach
  iserach(a,5,max);

  return 0;
}
