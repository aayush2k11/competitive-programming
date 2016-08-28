// Problem URL: https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list
#include<cstdio>
#include<iostrea>
using namespace std;

   // Reverse a doubly linked list, input list may also be empty
   // Node is defined as
struct Node {
     int data;
     Node *next;
     Node *prev;
}

Node* Reverse(Node* head)
{
    // Complete this function
    // Do not write the main method.
    Node *curr, *next, *previous = NULL;
    if (head){
        curr = head;
        next = curr->next;
        while(curr->next!=NULL){
            curr->next = previous;
            curr->prev = next;
            previous = curr;
            curr = next;
            next = curr->next;
        }
        curr->next = previous;
        curr->prev = NULL;
        head = curr;
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
    cout << Reverse(head) << endl;
  }
  return 0;
}