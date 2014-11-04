//Victor Guerra <vguerra@gmail.com>
//20141104

//https://www.hackerrank.com/challenges/compare-two-linked-lists

int CompareLists(Node *headA, Node* headB) {
  while(headA != nullptr && headB != nullptr) {
    if (headA->data != headB->data) return 0;
    headA = headA->next;
    headB = headB->next;
  }
  return ((headA == headB) ? 1 : 0);
}
