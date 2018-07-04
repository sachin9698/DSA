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
// int findmin(bstnode* root){
//   bstnode* current=root;
//   if(current==NULL){
//     cout<<"tree is empty !"<<endl;
//     return -1;
//   }
//   while (current->left==NULL) {
//     return current->data;
//   }
//   return findmin(current->left);
// }

struct bstnode* findmin(bstnode* root){    //findmin for deletion fumction
  bstnode* current=root;
  if(current==NULL){
    cout<<"tree is empty !"<<endl;
    return current;
  }
  while (current->left==NULL) {
    return current;
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

//***************************preorder********************************
void preorder(bstnode* root){
  if(root==NULL) return;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
  }

//***************************inorder********************************
  void inorder(bstnode* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    }

//***************************postorder********************************
    void postorder(bstnode* root){
      if(root==NULL) return;
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
      }


//************************deletion********************************
struct bstnode* Delete(struct bstnode* root, int data){
  if(root==NULL) return root;
  else if(data<root->data) root->left=Delete(root->left,data);
  else if(data>root->data) root->right=Delete(root->right,data);
  else{
    if(root->left==NULL && root->right==NULL){
      delete root;
      root=NULL;
    }
    else if(root->left==NULL){
      struct bstnode* temp=root;
      root=root->right;
      delete temp;
    }
    else if(root->right==NULL){
      struct bstnode* temp=root;
      root=root->left;
      delete temp;
    }
    else{
      struct bstnode* temp=findmin(root->right);
      root->data=temp->data;
      root->right=Delete(root->right,temp->data);
    }
  }
  return root;
}

//*********************************************************

int main(){
  bstnode* root=NULL;
  bstnode* root2=NULL;
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

  // preorder(root);
  root2=Delete(root,10);
  inorder(root);
  // postorder(root);

}
