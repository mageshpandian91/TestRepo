#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* newnode(int data){
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

struct node* mirror(struct node *root){
  if(root == NULL){
    return NULL;
  }
  else{
    struct node *temp = mirror(root->left);
    root->left = mirror(root->right);
    root->right = temp;
    return root;
  }
}

void inorder(struct node *root){
  if(root){
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
  }
}

void main(){
  struct node *root = newnode(1);
  root->left = newnode(2);
  root->right = newnode(3);
  root->left->left = newnode(4);
  root->left->right = newnode(5);
  root->right->left = newnode(6);
  root->right->right = newnode(7);
  printf("before mirror\n");
  inorder(root);
  struct node *ptr = mirror(root);
  printf("after mirror\n");
  inorder(root);
}