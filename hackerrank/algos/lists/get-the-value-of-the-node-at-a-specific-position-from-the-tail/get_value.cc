//Victor Guerra <vguerra@gmail.com>
//20141105

//https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail

int GetNode(Node *head, int positionFromTail) {
  Node *runner = head;
  while (positionFromTail-- && runner != nullptr) {
    runner = runner->next;
  }
  while (runner->next) {
    runner = runner->next;
    head = head->next;
  }
  return head->data;
}
