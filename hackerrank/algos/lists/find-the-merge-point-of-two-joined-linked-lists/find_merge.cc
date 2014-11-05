//Victor Guerra <vguerra@gmail.com>
//20141105

//https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists

int FindMergeNode(Node *headA, Node *headB)
{
  std::size_t countA = 0;
  std::size_t countB = 0; 

  Node *runnerA = headA;
  while (runnerA) {
    ++countA;
    runnerA = runnerA->next;
  }

  Node *runnerB = headB;
  while (runnerB) {
    ++countB;
    runnerB = runnerB->next;
  }

  if (countA > countB) {
    for (std::size_t tmp = 0; tmp < (countA - countB); tmp++) {
      headA = headA->next; 
    }
  } else if (countA != countB) {
    for (std::size_t tmp = 0; tmp < (countB - countA); tmp++) {
      headB = headB->next; 
    }
  }
  
  while (headA != headB) {
    headA = headA->next;
    headB = headB->next;
  }
  return headA->data;
}
