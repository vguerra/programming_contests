//Victor Guerra <vguerra@gmail.com>
//20141106

//https://www.hackerrank.com/challenges/reverse-a-linked-list

Node* Reverse(Node *head)
{
  Node *prev_p = nullptr;

  while (head) {
    Node *tmp = head->next;
    head->next = prev_p;
    prev_p = head;
    head = tmp;
  }
  return prev_p;
}
