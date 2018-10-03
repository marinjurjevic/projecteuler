/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main(void){
    unsigned long long int N = 600851475143L;
    unsigned long long int factor = 2;
    unsigned long long int lastFactor = 1;

    while( N > 1){
        if(N % factor == 0){
            lastFactor = factor;
            N = N / factor;
            while(N % factor == 0){
                N = N / factor;
            }
        }
        factor = factor+1;
    }

    cout << lastFactor;

    return 0;
}
