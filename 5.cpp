/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define k 20

bool isPrime(int number){
    bool flag = false;
    for(int i=2; i<=sqrt(number); ++i)
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

vector<int> getPrimes(int n){
	vector<int> v;
	for(int i = 2; i<n; i++){
		if(isPrime(i)){
			v.push_back(i);
		}
	}
	return v;
}

int digni(int b, int e){
	int r = 1;
	for(int i = 0; i<e; i++){
		r*=b;
	}
	return r;
}

int main(void){
    
	vector<int> p = getPrimes(k);
	int N = 1;
	int i = 0;
	bool check = true;
	int limit = (int)sqrt(k);
	while(i<p.size()){
		int a = 1;
		if(check){
			if( p[i] <= limit){
				a = floor( log(k) / log(p[i]) );
			}else{
				check = false;
			}
		}
		cout <<p[i] << " " << a << " " << N << endl;
		cout << digni(p[i], a) << endl;
		N = N* digni(p[i], a);
		i++;
	}
	
    cout << N;

    return 0;
}
