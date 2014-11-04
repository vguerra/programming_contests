//Victor Guerra <vguerra@gmail.com>
//20141104

//https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list

Node *Delete(Node *head, int position) {
  if (position == 0) {
    head = head->next;
    return head;
  }

  Node *prev = head;
  Node *runner = head->next;
  
  while (--position) {
    prev = runner;
    runner = runner->next;
  
  }
  prev->next = runner->next;
  return head;
}


