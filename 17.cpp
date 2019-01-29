/*


If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

*/

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<int, string> table = {
    {0, ""},
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "fifteen"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eighteen"},
    {19, "nineteen"},
    {20, "twenty"},
    {30, "thirty"},
    {40, "forty"},
    {50, "fifty"},
    {60, "sixty"},
    {70, "seventy"},
    {80, "eighty"},
    {90, "ninety"}};

vector<int> analyze(int n) {
  vector<int> v;
  while (n > 0) {
    v.push_back(n % 10);
    n = n / 10;
  }

  return v;
}

int main() {
  int sum = 11;
  for (int i = 1; i < 1000; i++) {
    vector<int> d = analyze(i);
    int s = d.size();

    if (s == 3) {
      s--;
      sum += table[d[2]].size();
      sum += 7;
      cout << table[d[2]] << "hundred ";
      if (i % 100 != 0) {
        cout << " and ";
        sum += 3;
      }
    }

    if (s == 1) {
      cout << table[i] << endl;
      sum += table[i].size();
    } else {
      if (d[1] == 1) {
        cout << table[i % 100] << endl;
        sum += table[i % 100].size();
      } else {
        string letters = table[d[1] * 10] + table[d[0]];
        cout << letters << endl;
        sum += letters.size();
      }
    }
  }

  cout << sum << endl;
  return 0;
}