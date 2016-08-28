// Problem URL: https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list
#include<cstdio>
#include<iostream>
using namespace std;

struct Node {
     int data;
     Node *next;
     Node *prev;
};

Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method.
  Node *temp;
    if (!head){
        head = new Node;
        head->data = data;
        head->prev = head->next = NULL;
        return head;
    } else {
        Node *curr, *prev, *next;
        prev = NULL;
        curr = head;
        next = curr->next;
        if (head->data >= data){
            Node *temp = new Node;
            temp->data = data;
            temp->next = head;
            head->prev = temp;
            temp->prev = NULL;
            head = temp;
            return head;
        } else {
            while (curr && curr->data < data){
                prev = curr;
                curr = (next == NULL) ? NULL : next;
                next = (curr == NULL ) ? NULL : curr->next;
            }
            temp = new Node;
            temp->data = data;
            temp->next = NULL;
            temp->prev = NULL;
            if (curr != NULL){
                temp->next = curr;
                temp->prev = prev;
                curr->prev = temp;
                prev->next = temp;
            } else {
                temp->next = NULL;
                temp->prev = prev;
                prev->next = temp;
            }
            return head;
        }
    }
    return head;
}

int main(){
  int  n, data;
  cin >> n;
  Node *head=NULL, *curr, *temp;
  for (int i=0;i<n;i++){
    cin >> data;
    if (i==0){
      head = new Node;
      head->data = data;
      head->next = NULL;
      head->prev = NULL;
      curr = head;
    } else {
      temp = new Node;
      temp->data = data;
      temp->next = NULL;
      temp->prev = curr;
      curr->next = temp;
      curr = temp;
    }
  }
  head = SortedInsert(head, 6);
  curr = head;
  while (curr!=NULL){
    cout << "prev: " << curr->prev << ", curr: " << curr->data << ", next: " << curr->next << endl;
    curr = curr->next;
  }
  return 0;
}