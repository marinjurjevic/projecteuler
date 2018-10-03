#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

const int DIGITS = 50;
const int N = 100;

int **matrix;

void allocateMatrix() {
  matrix = new int *[N];
  for (int i = 0; i < N; ++i) {
    matrix[i] = new int[DIGITS];
  }
}

void freeMatrix() {
  for (int i = 0; i < N; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void printMatrix() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < DIGITS; j++) {
      cout << matrix[i][j];
    }
    cout << endl;
  }
}

void calculate() {
  int carry = 0;
  int sum;
  stack<int> stack;

  for (int i = DIGITS - 1; i >= 0; i--) {
    sum = 0;
    for (int j = 0; j < N; j++) {
      sum += matrix[j][i];
    }
    sum += carry;

    if (i == 0) {
      stack.push(sum);
    } else {
      stack.push(sum % 10);
      carry = sum / 10;
      cout << carry << endl;
    }
  }

  for (int i = 0; i < DIGITS; i++) {
    cout << stack.top();
    stack.pop();
  }
}

int main() {
  string a = "123";
  allocateMatrix();

  int testSum1 = 0;
  int testSum2 = 0;
  for (int i = 0; i < N; i++) {
    cin >> a;
    for (int j = 0; j < DIGITS; j++) {
      matrix[i][j] = a[j] - '0';
      if (j == DIGITS - 1) {
        testSum1 += matrix[i][j];
      } else if (j == DIGITS - 2) {
        testSum2 += matrix[i][j];
      }
    }
  }
  cout << testSum1 << endl;
  cout << testSum2 << endl;
  // printMatrix();
  calculate();
  freeMatrix();
  return 0;
}