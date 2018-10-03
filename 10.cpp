/*

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*/

#include <iostream>
#include <cmath>

using namespace std;

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
    
	unsigned long long int sum = 2;
	
	for(int i = 3; i<2000000; i++){
		if(isPrime(i)){
			sum+=i;
		}
	}
	
	cout << sum;
	
    return 0;
}
