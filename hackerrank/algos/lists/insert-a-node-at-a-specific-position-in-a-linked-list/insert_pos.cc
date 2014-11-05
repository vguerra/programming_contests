//Victor Guerra <vguerra@gmail.com>
//20141105

//https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list

Node* InsertNth(Node *head, int data, int position)
{
  Node *new_node = new Node();
  new_node->data = data;
  new_node->next = nullptr;

  Node *runner = head;
  Node *prev = nullptr;
 
  while (position--) {
    prev = runner;
    runner = runner->next;
  }
  if (prev) {
    new_node->next = prev->next;
    prev->next = new_node;
  } else {
    new_node->next = head;
    head = new_node;
  }
  return head;
}
