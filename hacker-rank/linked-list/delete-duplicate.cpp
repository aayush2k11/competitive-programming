//  Problem URL: https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list
#include<cstdio>
#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission.
  // You only need to complete this method.
    Node *next, *curr, *same;
    curr = head;
    while(curr->next!=NULL){
        same = curr->next;
        while(same->next != NULL && same->data == curr->data){
            same = same->next;
        }
        if(same->next == NULL && same->data == curr->data){
           curr->next=NULL;
        } else{
            curr->next = same;
            curr=same;
        }
    }
    return head;
}


int main(){
  int tc, n, data;
  cin >> tc;
  while (tc--){
    cin >> n;
    Node *head=NULL, *curr, *temp;
    for (int i=0;i<n;i++){
      cin >> data;
      if (i==0){
        head = new Node;
        head->data = data;
        head->next = NULL;
        curr = head;
      } else {
        temp = new Node;
        temp->data = data;
        temp->next = NULL;
        curr->next = temp;
        curr = temp;
      }
    }
    RemoveDuplicates(head);
  }
  return 0;
}