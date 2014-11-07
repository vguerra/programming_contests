//Victor Guerra <vguerra@gmail.com>
//20141107

//https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse

#include <iostream>
#include <stack>

void ReversePrint(Node *head)
{
  std::stack<int> pile;
  while (head) {
    pile.push(head->data);
    head = head->next;
  }

  while (!pile.empty()) {
    std::cout << pile.top() << "\n";
    pile.pop();
  }
}
