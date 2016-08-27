// Problem URL: https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists
#include<cstdio>
#include<iostrea>
using namespace std;

  // Merge two sorted lists A and B as one linked list
  // Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }

Node* MergeLists(Node *headA, Node* headB){
  // This is a "method-only" submission.
  // You only need to complete this method
    Node *head=NULL, *curr1, *curr2, *curr, *temp;
    if (headA && headB){
        head = new Node;
        if (headA->data <= headB->data){
            head->data = headA->data;
            head->next = NULL;
            curr1 = headA->next;
            curr2 = headB;
        } else {
            head-> data = headB->data;
            head->next = NULL;
            curr2 = headB->next;
            curr1 = headA;
        }
        curr = head;
        while (curr1 && curr2){
            temp = new Node;
            if (curr1->data <= curr2->data){
                temp->data = curr1->data;
                curr1 = curr1->next;
            } else {
                temp->data = curr2->data;
                curr2 = curr2->next;
            }
            temp->next = NULL;
            curr->next = temp;
            curr = temp;
        }
        if (curr1){
            curr->next = curr1;
        } else if (curr2){
            curr->next = curr2;
        }
        return head;
    } else {
        if (headA)
            return headA;
        else return headB;
    }
}

int main(){
  int tc, n1, n2;
  cin >> tc;
  while(tc--){
    cin >> n1;
    Node *headA=NULL, *curr, *temp;
    for (int i=0;i<n;i++){
      cin >> data;
      if (i==0){
        headA = new Node;
        headA->data = data;
        headA->next = NULL;
        curr = headA;
      } else {
        temp = new Node;
        temp->data = data;
        temp->next = NULL;
        curr->next = temp;
        curr = temp;
      }
    }
    cin >> n2;
    Node *headB=NULL, *curr, ;
    for (int i=0;i<n;i++){
      cin >> data;
      if (i==0){
        headB = new Node;
        headB->data = data;
        headB->next = NULL;
        curr = headB;
      } else {
        temp = new Node;
        temp->data = data;
        temp->next = NULL;
        curr->next = temp;
        curr = temp;
      }
    }
    MergeLists(headA, headB);
  }
  return 0;
}