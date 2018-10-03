#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

#define L 4

// globals
int R, C;
int **matrix;
int maxSum = 0;

int dirY[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dirX[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool checkBounds(int x, int y) {
  if (x < 0 || x >= C) {
    return false;
  }
  if (y < 0 || y >= R) {
    return false;
  }

  return true;
}

void start() {
  int x, y;
  int sum;
  int mx, my;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      for (int d = 0; d < 8; d++) {  // 8 directions
        y = i;
        x = j;
        sum = 1;
        for (int k = 0; k < L; k++) {
          if (checkBounds(x, y)) {
            sum *= matrix[y][x];
            y += dirY[d];
            x += dirX[d];
          } else {
            sum = 1;
            break;
          }
        }
        if (sum > maxSum) {
          mx = x;
          my = y;
          maxSum = sum;
        }
      }
    }
  }
  cout << mx << " " << my << " " << endl;
  cout << maxSum << endl;
}

void allocateMatrix() {
  matrix = new int *[R];
  for (int i = 0; i < R; ++i) {
    matrix[i] = new int[C];
  }
}

void freeMatrix() {
  for (int i = 0; i < R; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void printMatrix() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout << setw(4) << matrix[i][j];
    }
    cout << endl;
  }
}
int main(void) {
  cin >> R >> C;
  allocateMatrix();
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> matrix[i][j];
    }
  }

  printMatrix();
  start();
  freeMatrix();
  return 0;
}