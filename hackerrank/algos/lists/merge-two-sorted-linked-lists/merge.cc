// Victor Guerra <vguerra@gmail.com>
// 20141106

// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists

Node *MergeLists(Node *headA, Node *headB) {
  if (headA == nullptr) return headB;
  if (headB == nullptr) return headA;

  Node *new_head = nullptr;
  Node *last = nullptr;

  if (headA->data < headB->data) {
    new_head = headA;
    headA = headA->next;
  } else {
    new_head = headB;
    headB = headB->next;
  }
  last = new_head;

  while (headA && headB) {
    if (headA->data < headB->data) {
      last->next = headA;
      headA = headA->next;
    } else {
      last->next = headB;
      headB = headB->next;
    }
    last = last->next;
  }
  if (headA == nullptr) {
    last->next = headB;
  } else {
    last->next = headA;
  }
  return new_head;
}
