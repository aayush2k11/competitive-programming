#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
struct node {
  int value;
  int height;
  struct node *left, *right;
};

int height(node *root){
  if (root == NULL)
    return 0;
  return root->height;
}

node *new_node(int key){
  node *root = new node;
  root->value = key;
  root->left = root->right = NULL;
  root->height = 1;
  return root;
}

int get_balance(node *root){
  if(root == NULL)
    return 0;
  return height(root->left) - height(root->right);
}

node *right_rotate(node *root){
  node *x = root->left;
  node *y = x->right;
  x->right = root;
  root->left = y;
  x->height = max(height(x->left), height(x->right)) + 1;
  root->height = max(height(root->left), height(root->right)) + 1;
  return x;
}

node *left_rotate(node *root){
  node *x = root->right;
  node *y = x->left;
  x->left = root;
  root->right = y;
  x->height = max(height(x->left), height(x->right)) + 1;
  root->height = max(height(root->left), height(root->right)) + 1;
  return x;
}


node *insert(node *root, int value){
  if (root == NULL)
    return new_node(value);

  if (value < root->value){
    root->left = insert(root->left, value);
  } else {
    root->right = insert(root->right, value);
  }
  root->height = max(height(root->left), height(root->right)) + 1;
  int balance = get_balance(root);
  if (balance > 1 && value < root->left->value)
    return right_rotate(root);
  else if (balance < -1 && value > root->right->value)
    return left_rotate(root);

  if (balance > 1 && value > root->left->value){
    root->left = left_rotate(root->left);
    return right_rotate(root);
  }
  if (balance < -1 && value < root->right->value){
    root->right = right_rotate(root->right);
    return left_rotate(root);
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

bool search(node *root, int key){
  if (root == NULL)
    return false;
  if (root && root->value == key)
    return true;
  if (root && root->value > key)
    return search(root->left, key);
  if (root && root->value < key)
    return search(root->right, key);
  return false;
}

// node *min_value_node(node *root){
//   node *current = root->right;
//   while (current->left)
//     current = current->left;
//   return current;
// }

// node *delete_node(node *root, int key){
//   if (root == NULL)
//     return root;
//   if (key < root->value){
//     root->left = delete_node(root->left, key);
//   } else if (key > root->value){
//     root->right = delete_node(root->right, key);
//   } else {
//     if (root->left == NULL){
//       node *temp = root->right;
//       free(root);
//       return temp;
//     } else if (root->right == NULL){
//       node *temp = root->left;
//       free(root);
//       return temp;
//     } else {
//       node *successor = min_value_node(root);
//       root->value = successor->value;
//       root->right = delete_node(root->right, successor->value);
//     }
//     return root;
//   }
//   return root;
// }

int main(){
  node *root;
  root = NULL;
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 25);
  root = insert(root, 35);
  root = insert(root, 28);
  root = insert(root, 16);
  root = insert(root, 7);
  root = insert(root, 83);
  cout << "Inorder traversal: " << endl;
  inorder_traversal(root);
  cout << endl << "===============================" << endl;
  cout << "Preorder traversal" << endl;
  preorder_traversal(root);
  cout << endl << "===============================" << endl;
  cout << "Postorder traversal" << endl;
  postorder_traversal(root);
  cout << endl << "===============================" << endl;
  return 0;
}