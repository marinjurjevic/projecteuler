/*

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

*/

#include <iostream>

using namespace std;

typedef long long big;
const big L = 1000000L;

int collatz(big n) {
  static int k = 1;
  if (n == 1) {
    int value = k;
    k = 1;
    return value;
  }
  k++;
  if (n & 1) {
    return collatz(3 * n + 1);
  } else {
    return collatz(n / 2);
  }
}

void brute_force() {
  int maks = 0;
  int value;
  int n;
  for (int i = 2; i < L; i++) {
    value = collatz(i);
    if (value >= maks) {
      maks = value;
      n = i;
    }
  }

  cout << n << " " << maks << endl;
}

int main() {
  brute_force();
  return 0;
}