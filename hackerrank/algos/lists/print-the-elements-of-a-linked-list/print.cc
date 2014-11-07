Victor Guerra <vguerra@gmail.com>
20141107

https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list

void Print(Node *head)
{
  while (head) {
    std::cout << head->data << "\n";
    head = head->next;
  }
}
