//Victor Guerra <vguerra@gmail.com>
//20141107

//https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list

Node* Reverse(Node* head)
{
  Node *tmp = nullptr;
  Node *prev = nullptr;;
  while (head) {
    Node *tmp = head->next;

    head->next = head->prev;
    head->prev = tmp;
    prev = head;
    head = tmp;
  }
  return prev;
}


