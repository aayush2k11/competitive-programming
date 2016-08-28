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

int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method.
    Node *temp1 = headA, *temp2 = headB;
    int count1=0, count2=0, diff;
    while(temp1->next!=NULL){
        count1++;
        temp1 = temp1->next;
    }
    count1++;
    while(temp2->next!=NULL){
        count2++;
        temp2 = temp2->next;
    }
    count2++;
    temp1 = headA, temp2=headB;
    if(count1>count2){
        diff = count1-count2;
        for(int i=0;i<diff;i++){
            temp1 = temp1->next;
        }
    } else if(count1<count2){
        diff = count2-count1;
        for(int i=0;i<diff;i++){
            temp2 = temp2->next;
        }
    }
    while(temp1->next!=NULL && temp2->next!=NULL){
        if(temp1->next == temp2->next && temp1->next->data == temp2->next->data){
            return temp1->next->data;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return 0;
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
    cout << FindMergeNode(headA, headB) << endl;
  }
  return 0;
}