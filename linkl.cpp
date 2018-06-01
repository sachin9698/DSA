// linked list

#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
};

class linkl {
private:
  node *head, *tail;

public:
  linkl (){
    head=NULL;
    tail=NULL;
  }
// add at tail
  void add_node_t(int n){
    node *temp=new node;
    temp->data=n;
    temp->next=NULL;

    if(head==NULL){
      head=temp;
      tail=temp;
    }
    else
    {
      tail->next=temp;
      tail=tail->next;
    }
  }

// add at head

  void add_node_h(int n){
    node *temp=new node;
    temp->data=n;
    temp->next=NULL;

    if(head==NULL){
      head=temp;
      tail=temp;
    }
    else
    {
      temp->next=head;
      head=temp;
    }
  }

// add at position

  void add_node_p(int n,int p){
    node *temp=new node;
    temp->data=n;
    temp->next=NULL;
    node *temp2=head;
    node *temp3;

   p=p-1;

while(p!=0){
  temp3=temp2;
  temp2=temp2->next;
  p--;
}

temp3->next=temp;
temp->next=temp2;

  }

  void dell(){

    int p,counter=0;
    cout<<"\nenter the postion of the value to be delted :";
    cin>>p;

    if(head==NULL){
      cout<<"link list is empty nothing to delete !"<<endl;
      return;
    }

    node *s,*ptr;
    s=head;
    if(p==1){
      head=s->next;
    }
    else{
      while (s!=NULL) {
        s=s->next;
        counter++;
      }
      // cout<<counter<<endl;
      if(p>0 && p<=counter){
        s=head;
        for(int i=1;i<p;i++){
          ptr=s;
          s=s->next;
        }
        ptr->next=s->next;
      }
      else{
        std::cout << "postion out of range !" << '\n';
      }
    }


  }

void searchl(){
  int v,p=0;
  cout<<"\nenter the value to be searched in the link list :";
  cin>>v;
  node *temp;
  temp=head;
  while(temp != NULL){
    if(temp->data==v){
      p=1;
      cout<<v<<" found"<<endl;
    }
    temp=temp->next;
  }
  if(p==0){
    cout<<v<<" not found"<<endl;
  }
}



  void printl() {
    node *temp=new node;
    if(head==NULL){
      cout<<"list is empty !";
      return;
    }
    temp=head;
    while (temp!=NULL){
      cout<<temp->data<<" ";
      temp=temp->next;
    }
  }
};

int main() {
  linkl a;
  a.add_node_t(1);
  a.add_node_t(2);
  a.add_node_t(3);
  a.add_node_h(4);
  a.add_node_t(5);
  a.add_node_p(12,4);
  a.printl();
  // a.dell();
  // a.printl();
  a.searchl();
  cout<<endl;
  return 0;
}
