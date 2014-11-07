//Victor Guerra <vguerra@gmail.com>
//20141107

//https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list

Node* SortedInsert(Node *head,int data)
{
  Node *new_node_p = new Node();
  new_node_p->data = data;
  new_node_p->prev = nullptr;
  new_node_p->next = nullptr;
  
  if (head == nullptr) {return new_node_p;}
  if (head->data >= data) {
    new_node_p->next = head;
    head->prev = new_node_p;
    return new_node_p;
  }

  Node *runner_p = head;

  while (runner_p->next && runner_p->next->data < data) {
    runner_p = runner_p->next; 
  }
  
  new_node_p->next = runner_p->next;
  runner_p->next = new_node_p;
  new_node_p->prev = runner_p;
  if (new_node_p->next) {
    new_node_p->next->prev = new_node_p;
  }
  return head;
}
