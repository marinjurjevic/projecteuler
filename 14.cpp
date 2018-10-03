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