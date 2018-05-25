// array

//insertion into array

// #include <iostream>
// using namespace std;
//
// int main(){
//      int a[]={1,2,3,4,5};
//
//      int n=sizeof(a)/sizeof(int);
//      int k;
//      cout<<"enter the position to insert the element :";
//      cin>>k;
//      k=k-1;
//      int p;
//      cout<<"enter the element :";
//      cin>>p;
//      int j=n;
//      for(int i=0;i<n;i++){
//        cout<<a[i]<<" ";
//      }
//
//      n=n+1;
//
//      while(j>=k){
//        a[j+1]=a[j];
//        j--;
//      }
//     a[k]=p;
//     cout<<"\n";
//      for(int i=0; i<n;i++){
//        cout<<a[i]<<" ";
//      }
// return 0;
// }



//deletion into array

#include <iostream>
using namespace std;

int main(){
     int a[]={1,2,3,4,5};

     int n=sizeof(a)/sizeof(int);

     int p;
     cout<<"enter the element :";
     cin>>p;
     int j=n;
     int k,q=0;
     for(int i=0;i<n;i++){
       if(p==a[i]){
          k=i;
          q=1;
       }
     }
     if(q==0){
       cout<<"\nelement not found !";
       return 0;
     }


     while(k<=n){
       a[k]=a[k+1];
       k++;
     }
    n=n-1;
    cout<<"\n";
     for(int i=0; i<n;i++){
       cout<<a[i]<<" ";
     }
return 0;
}
