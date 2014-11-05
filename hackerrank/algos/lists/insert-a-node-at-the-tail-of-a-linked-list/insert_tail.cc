//Victor Guerra <vguerra@gmail.com>
//20141105

//https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list

Node* Insert(Node *head,int data)
{
  Node *current_tail = head;
  Node *new_tail = new Node();
  new_tail->next = nullptr;
  new_tail->data = data;
  
  if (head == nullptr) {
    head = new_tail;
  } else {
    while (current_tail->next) {
      current_tail = current_tail->next;
    }
    current_tail->next = new_tail;
  }
  return head;
}
