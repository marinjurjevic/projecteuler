/*
If we list all the natural numbers below 10 that are multiples of 3 or 5,
we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

*/

#include <iostream>

using namespace std;

int main(void){
    int sum = 0;

    for(int i = 3, j = 5; i<1000; i+=3, j+=5){
        sum = sum + (i%5==0?0:i) + (j<1000?j:0);
    }

    cout << sum;

    return 0;
}
