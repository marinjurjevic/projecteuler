/*

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>

using namespace std;

#define SQR(x) ((x)*(x))

int main(void){
    
	for(int i = 0; i<=1000; i++){
		for(int j = i + 1 ; j<=1000; j++){
			for(int k = j + 1; k<=1000; k++){
				if(k+j+i == 1000){
					if(SQR(i)+SQR(j) == SQR(k)){
						cout << i << " " << j << " " << k << endl;
						cout << i*j*k << endl;
						return 0;
					}
				}
			}
		}
	}
	
    return 0;
}
