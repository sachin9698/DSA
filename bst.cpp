#include <iostream>
#include <math.h>
#include<queue>
using namespace std;

struct bstnode{
  int data;
  bstnode* left;
  bstnode* right;
};

bstnode* getnewnode(int data){
  bstnode* newnode = new bstnode();
  newnode->data=data;
  newnode->left=newnode->right=NULL;
  return newnode;
}

bstnode* insert(bstnode* root, int data){
  if(root==NULL){
    root=getnewnode(data);
  }
  else if(data<=root->data){
    root->left=insert(root->left,data);
  }
  else{
    root->right=insert(root->right,data);
  }
  return root;
}

bool search(bstnode* root, int data){
  if(root==NULL){
    return false;
  }
  else if(root->data==data){
    return true;
  }
  else if(data <= root->data){
    return search(root->left,data);
  }
  else{
    return search(root->right,data);
  }
}

//****************************using iteration******************************

// int findmin(bstnode* root){
//   bstnode* current=root;
//   if(current==NULL){
//     cout<<"tree is empty !"<<endl;
//     return -1;
//   }
//   while (current->left!=NULL) {
//     current=current->left;
//   }
//   return current->data;
// }

//****************************using recursion******************************
int findmin(bstnode* root){
  bstnode* current=root;
  if(current==NULL){
    cout<<"tree is empty !"<<endl;
    return -1;
  }
  while (current->left==NULL) {
    return current->data;
  }
  return findmin(current->left);
}

// //****************************using recursion******************************
// int findmax(bstnode* root){
//   bstnode* current=root;
//   if(current==NULL){
//     cout<<"tree is empty !"<<endl;
//     return -1;
//   }
//   else if(current->right==NULL) {
//     return current->data;
//   }
//   return findmax(current->right);
// }

// //****************************using iteration******************************

int findmax(bstnode* root){
  bstnode* current=root;
  if(current==NULL){
    cout<<"tree is empty !"<<endl;
    return -1;
  }
  while (current->right!=NULL) {
    current=current->right;
  }
  return current->data;
}

//*************************height of tree******************************
int findheight(bstnode* root){
  if(root==NULL){
    return -1;
  }
  int l=findheight(root->left);
  int r=findheight(root->right);

  return max(l,r)+1;
}

//*************************level order or BFS*************************
void levelorder(bstnode* root){
  if(root==NULL) return;
  queue<bstnode*> q;
  q.push(root);
  while (!q.empty()) {
    bstnode* current =q.front();
    cout<<current->data<<" ";
    if(current->left!=NULL) q.push(current->left);
    if(current->right!=NULL) q.push(current->right);
    q.pop();
  }
}


//*********************************************************

int main(){
  bstnode* root=NULL;
  root=insert(root,15);
  root=insert(root,10);
  root=insert(root,20);
  root=insert(root,8);
  root=insert(root,12);
  root=insert(root,17);
  root=insert(root,25);
  root=insert(root,22);

  // int number;
	// cout<<"Enter number be searched\n";
	// cin>>number;
	// //If number is found, print "FOUND"
	// if(search(root,number) == true) cout<<"Found\n";
	// else cout<<"Not Found\n";

  // int min=findmax(root);
  // cout<<min<<endl;

  // int height=findheight(root);
  // cout<<"height of the tree is :"<<height<<endl;

  levelorder(root);

}
