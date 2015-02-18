//Victor Guerra <vguerra@gmail.com>
//20150203

//https://www.hackerrank.com/challenges/acm-icpc-team

#include <iostream>
#include <cstdlib>
#include <vector>

int main() {
  unsigned nPeople, nTopics;
  std::cin >> nPeople >> nTopics;

  std::vector<bool> topics_matrix(nPeople*nTopics, false);

  for (unsigned i = 0; i < nPeople; ++i) {
    std::string line; 
    std::getline(std::cin, line);
    for (unsigned j = 0; j < nTopics; ++j) {
      if (line[j] == '1') topics_matrix[i*nPeople + j] = true;
    }
  }

  unsigned max_topics = 0; 
  unsigned max_couples = 0; 

  for (unsigned p1 = 0; p1 < nPeople - 1; ++p1) {
    unsigned idx1 = p1*nPeople;
    for (unsigned p2 = p1 + 1; p2 < nPeople; ++p2) {
      unsigned topics = 0;
      unsigned idx2 = p2*nPeople;
      for (unsigned k = 0; k < nTopics; ++k) {
        if (topics_matrix[idx1 + k] | topics_matrix[idx2 + k]) ++topics;
      }
      if (topics == max_topics) {
        ++max_couples;
      } else if (topics > max_topics) {
        max_topics = topics;
        max_couples = 1;
      }
    }
  }
  std::cout << max_topics << "\n" << max_couples << "\n";
  return EXIT_SUCCESS;
}
