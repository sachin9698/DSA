#include <iostream>
using namespace std;
#define max 5


class queue {
private:
  int q[max];
  int f=0,r=0;

public:

  void enque(int n){
    if(f==0 && r==max){
      cout<<"queue is full !";
    }
    else {
      q[r]=n;
      r++;
    }

  }

 void deque(){
   if(f==r){
     cout<<"queue is empty !";
   }
   else{
     f++;
   }
 }

 void display(){
   int temp=f;
if(r==f){
  cout<<"queue is empty !";
}
else {
  for(int i=temp;i<r;i++){
    cout<<q[i]<<" ";
  }
  cout<<endl;
}
 }
};

int main(){
     queue qq;

     qq.enque(1);
     qq.enque(2);
     qq.enque(3);
     qq.enque(2);
     qq.enque(3);
     qq.deque();
     qq.deque();
     qq.deque();
     qq.deque();
     qq.deque();
      qq.display();
}
