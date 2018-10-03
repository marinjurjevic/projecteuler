/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

const unsigned long long int N = 600851475143L;

bool isPrime(unsigned long long int number){
    bool flag = false;
    for(unsigned long long int i=2; i<=sqrt(number); ++i)
    {
        // condition for nonprime number
        if(number%i==0)
        {
            flag=true;
            break;
        }
    }
    return !flag;
}

int main(void){
    unsigned long long int i = 997;
    unsigned long long int big_prime = 1;

    for(; i<sqrt(N); i++){
        if(N%i == 0 && isPrime(i)){
            big_prime = i;
        }
    }

    cout << big_prime;

    return 0;
}
