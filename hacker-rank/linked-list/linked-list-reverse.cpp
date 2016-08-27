//  Problem URL: https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse
#include<cstdio>
#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

void ReversePrint(Node *head)
{
  // This is a "method-only" submission.
  // You only need to complete this method.
    if (head == NULL)
        return;
    Node *next, *current, *previous;
    next = head->next;
    current = head;
    previous = NULL;
    while (current->next != NULL){
        current->next = previous;
        previous = current;
        current = next;
        next = current->next;
    }
    current->next = previous;
    while (current->next != NULL){
        cout << current->data << endl;
        current = current->next;
    }
    cout << current->data <<endl;
    return;
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
    ReversePrint(head);
  }
  return 0;
}