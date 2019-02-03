/*

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide
evenly into n). If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are
called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore
d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

*/

#include <iostream> 
#include <cmath> 
#include <vector>
#include <utility>

std::vector< std::pair<int,int> > factorize(int n) 
{ 
    int p = 2;
    int sum = 0;
    std::vector< std::pair<int,int> > v;
    do {
        if ( n % p == 0) {
            sum++;
            n /= p;
        }else{
            if(sum){
                v.push_back(std::make_pair(p,sum));
            }
            p++;
            sum = 0;
        }
    }while( sqrt(p) <= n);

    v.push_back(std::make_pair(p,sum));

    return v;
} 

int sumOfProperDivisors(int n) {
    std::vector< std::pair<int,int> > v = factorize(n);
    int product = 1;

    for(int i = 0; i < v.size(); i++){
        product*= ( ( pow( v[i].first , v[i].second + 1 ) - 1 ) / ( v[i].first - 1 ) );
    }

    return product - n;
}

int main() 
{ 
    int sum = 0;
    for(int a = 2; a < 9999; a++){
        int b = sumOfProperDivisors(a);
        if ( b > a && sumOfProperDivisors(b) == a) {
            sum += (a+b);
        }
    }
    
    std::cout << sum << std::endl;

    return 0; 
} 