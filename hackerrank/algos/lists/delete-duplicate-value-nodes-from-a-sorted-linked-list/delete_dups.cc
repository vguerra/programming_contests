//Victor Guerra <vguerra@gmail.com>
//20141104

//https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list

Node* RemoveDuplicates(Node *head) {
  Node *last = head;
  while (last != nullptr) {
    Node *runner = last->next;
    while (runner != nullptr && runner->data == last->data) {
      runner = runner->next;
    }
    last->next = runner;
    last = runner;
  }
  return head;
}
