//Victor Guerra <vguerra@gmail.com>
//20141105

//https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list

Node* Insert(Node *head, int data) {
  Node *new_node = new Node();
  new_node->next = head;
  new_node->data = data;
  head = new_node;
  return head;
}
