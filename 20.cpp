#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const string big = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";

int main() {
  int sum = 0;
  for (int i = 0; i < big.size(); i++) {
    if (big[i] != ' ') {
      sum += (big[i] - '0');
    }
  }
  cout << sum << endl;
  return 0;
}