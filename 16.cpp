/*

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?

*/

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const string big = "10 715 086 071 862 673 209 484 250 490 600 018 105 614 048 117 055 336 074 437 503 883 703 510 511 249 361 224 931 983 788 156 958 581 275 946 729 175 531 468 251 871 452 856 923 140 435 984 577 574 698 574 803 934 567 774 824 230 985 421 074 605 062 371 141 877 954 182 153 046 474 983 581 941 267 398 767 559 165 543 946 077 062 914 571 196 477 686 542 167 660 429 831 652 624 386 837 205 668 069 376";

int main() {
  int sum = 0;
  for (int i = 0; i < big.size(); i++) {
    if (big[i] != ' ') {
      sum += (big[i] - '0');
    }
  }
  cout << setprecision(1000) << pow(2, 1000) << endl;
  cout << sum << endl;
  return 0;
}