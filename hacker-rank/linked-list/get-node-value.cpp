// Problem URL: https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail
/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission.
  // You only need to complete this method.
    int count = 0, iterations;
    Node *temp = head;
    while(temp->next != NULL){
        count++;
        temp = temp->next;
    }
    iterations = count - positionFromTail;
    temp = head;
    for (int i=1;i<=iterations;i++){
        temp = temp->next;
    }
    return temp->data;
}

int main(){
  int tc, n, data, positon;
  cin >> tc;
  while (tc--){
    cin >> n >> position;
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
    cout << GetNode(head, position);
  }
  return 0;
}