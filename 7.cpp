/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <iostream>
#include <cmath>

using namespace std;

#define N 10001

typedef unsigned long long int big;


bool isPrime(big number){
    bool flag = false;
    for(big i=2; i<=sqrt(number); ++i)
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

void start(){
	
	big i=3;
	int counter = 1;
	while(true){
		if(isPrime(i)){
			counter++;
		}
		
		if(counter == N){
			break;
		}
		
		i+=2;
	}
	
	cout << i;
}


int main(void){
	start();
	
	return 0;
}