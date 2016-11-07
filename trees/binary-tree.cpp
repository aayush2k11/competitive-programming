#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
struct node {
  int value;
  struct node *left, *right;
};

node *insert(node *root, int value){
  if (root == NULL){
    root = new node;
    root->value = value;
    root->left = root->right = NULL;
  } else if (value <= root->value){
    if (root->left != NULL)
      insert(root->left, value);
    else {
      node *temp = new node;
      temp->value = value;
      temp->left = temp->right = NULL;
      root->left = temp;
    }
  } else if (value >= root->value){
    if (root->right != NULL)
      insert(root->right, value);
    else {
      node *temp = new node;
      temp->value = value;
      temp->left = temp->right = NULL;
      root->right = temp;
    }
  }
  return root;
}

void inorder_traversal(node *root){
  if (root == NULL)
    return;
  if (root && root->left)
    inorder_traversal(root->left);
  if (root != NULL)
    cout << root->value << " ";
  if (root && root->right)
    inorder_traversal(root->right);
  return;
}

void preorder_traversal(node *root){
  if (root == NULL)
    return;
  if (root)
    cout << root->value << " ";
  if (root && root->left)
    preorder_traversal(root->left);
  if (root && root->right)
    preorder_traversal(root->right);
  return;
}

void postorder_traversal(node *root){
  if (root == NULL)
    return;
  if (root && root->left)
    postorder_traversal(root->left);
  if (root && root->right)
    postorder_traversal(root->right);
  cout << root->value << " ";
  return;
}

int main(){
  node *root;
  root = NULL;
  root = insert(root, 20);
  root = insert(root, 10);
  root = insert(root, 30);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 25);
  root = insert(root, 35);
  cout << "Inorder traversal: " << endl;
  inorder_traversal(root);
  cout << endl << "===============================" << endl;
  cout << "Preorder traversal" << endl;
  preorder_traversal(root);
  cout << endl << "===============================" << endl;
  cout << "Postorder traversal" << endl;
  postorder_traversal(root);
  cout << endl;
  return 0;
}