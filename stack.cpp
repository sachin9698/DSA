#include <iostream>
using namespace std;
#define max 2


class stack {
private:
  int a[max];
  int top=-1;
public:

bool isempty(){
  if(top==-1){
    return true;
  }
  else return false;
}

bool isfull(){
  if(top==max) return true;
  else return false;
}

// int peek(){
//   if(!isempty()){
//     return a[top];
//   }
//   else cout<<"\nnothing to peek !";
// }

void push(int x){
  if(top==max-1){
    cout<<"\nStack is full ! can't push";
  }
  else{
    top++;
    a[top]=x;
  }
}


 void pop(){
   if(top==-1){
     cout<<"\nstck is empty ! can't pop\n";

   }
   else {
     top--;
 }
 }

 void display(){
   for(int i=0;i<=top;i++){
     cout<<a[i]<<" ";
   }
   cout<<endl;
 }

};



int main(){
stack s;

s.push(1);
s.display();
s.push(2);
s.display();
s.pop();
s.display();
s.push(3);
s.display();
s.push(3);
return 0;
}
