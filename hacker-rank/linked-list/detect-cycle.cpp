//  Problem URL: https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle
#include<cstdio>
#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node *x, *y;
    x = head;
    y = head;
    while(x!=NULL && y!=NULL){
        x=x->next;
        y=y->next;
        y=y->next;
        if(x==y){
            return 1;
        }
    }
    return 0;
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
    cout << has_cycle(head) << endl;
  }
  return 0;
}