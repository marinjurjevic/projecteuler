
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[]) {
  std::vector<std::string> names;
  std::ifstream in("22.in");

  std::string str;
  while(std::getline(in, str)) {
    names.push_back(str);
  }

  std::sort(names.begin(),names.end());

  int score = 0;
  for(int i = 0; i < names.size(); i++) {
    int value = 0;
    for (char c : names[i]) value += ((c - 'A') + 1);
    score += (value * (i + 1));
  }

  std::cout << score << '\n';

  return 0;
}