/*

Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

*/

#include <iostream>

using namespace std;

#define N 20

long int counter = 0;

void DFS(int x, int y) {
  if (x > N || y > N) return;
  if (x == N && y == N) {
    counter++;
    return;
  }

  DFS(x + 1, y);
  DFS(x, y + 1);
}

int main() {
  DFS(0, 0);
  cout << counter << endl;

  return 0;
}